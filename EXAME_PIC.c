int debounce;
void main(){
     UART1_Init(9600);
     
     TRISB = 0b00100000;
     TRISD.RD0 = 1;
     LATB = 0;
     debounce = 1;
     while(1){
       PORTB.RB0 = 1;
       if(PORTB.RB5 == 0){
         debounce = 0;
         delay_ms(50);
         if(PORTB.RB5 == debounce){
           LATB.RB7 = 1;
           UART1_Write('A');
           delay_ms(500);
           LATB.RB7 = 0;
         }
         debounce = 1;
       }
       if(PORTD.RD0 == 0){
         debounce = 0;
         delay_ms(50);
         if(PORTD.RD0 == debounce){
           LATB.RB6 = 1;
           UART1_Write('B');
           delay_ms(500);
           LATB.RB6 = 0;
         }
         debounce = 1;
       }
     }
}