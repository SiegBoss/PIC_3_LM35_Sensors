//Programa Para leer 3 Sensores de Temperatura LM35 y Mostrarlos en un LCD | Program to read 3 LM35 Temperature Sensors and Display them on an LCD

#include <16F877A.h> 
#device adc=10 
#fuses XT,NOWDT,NOPROTECT,NOLVP 
#use delay(clock=4000000)
#include <lcd.c>
#use fast_io(A)
#use fast_io(D)

//Declaracion de Variables | Declaration of Variables 
float entrada_1, entrada_2, entrada_3, salida_a_1,salida_a_2, salida_a_3;
 
//Programa Principal | Main Program 
void main() {   

  //Configuracion de los puertos de entrada y salida | Configuration of input and output ports 
  set_tris_D(0b00001000);
  //Configuracion del conversor analogico digital | Configuration of the analog digital converter 
  setup_adc(ADC_CLOCK_INTERNAL);  
  //Configuracion de los puertos analogicos | Configuration of analog ports */       
  setup_adc_ports(AN0_AN1_AN3);
  //Inicializacion del LCD | LCD initialization 
  lcd_init();

  //Mensaje en el LCD | Message on the LCD 
  lcd_gotoxy(1,1);
  printf(lcd_putc, "TP1   TP2   TP3");

  //Ciclo infinito | Infinite loop 
  while (TRUE) {

    //Lectura de los valores de los sensores | Reading the values of the sensors
    set_adc_channel(0);
    entrada_1 = read_adc();
    salida_a_1 = entrada_1/2;
   
    set_adc_channel(1);
    entrada_2 = read_adc();
    salida_a_2 = entrada_2/2;
   
    set_adc_channel(3);
    entrada_3 = read_adc();
    salida_a_3 = entrada_3/2;

    //Impresion de los valores de los sensores en el LCD | Printing the values of the sensors on the LCD
    lcd_gotoxy(1,2);
    printf(lcd_putc,"%3.0f   %3.0f   %3.0f",salida_a_1, salida_a_2 ,salida_a_3); 
  }
}

