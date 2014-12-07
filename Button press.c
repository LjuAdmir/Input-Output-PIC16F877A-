/*
  MCU Name: PIC 16F877A
  MCU Clock Frequency: 12MHz
  */
void main() {
TRISD.F0 = 1;  //RD0 = input (switch)
TRISD.F1 = 1;  //RD1 = input (switch)
TRISB.F0 = 0;  //RB0 = output (LED)
PORTB.F0 = 0;  //RB0 = off (LED)
 do
 {
  if(PORTD.F0 == 1 || PORTD.F1 == 1)  //if RD0 or RD1 = pressed
  {
   Delay_ms(100);   //Switch Debounce
   if(PORTD.F0 == 1)   //if RD0 is still pressed
   {
    PORTB.F0 = 1;   //RB0 = 1 (LED ON)
   }
   if(PORTD.F1 == 1)   //if RD1 is still pressed
   {
    PORTB.F0 = 0;    //RB0 = 0 (LED OFF)
   }
  }
 }while(1);
}