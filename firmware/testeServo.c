#include <testeServo.h>

long pwmHigh = 55;

#INT_TIMER2
void  TIMER2_isr(void){
   static long totalInt;
   if(totalInt < 1250) totalInt++;
   else totalInt = 0;
   if(totalInt >= 0 && totalInt < (pwmHigh)) output_high(PIN_A0);
   else output_low(PIN_A0);
}

void main(){
   setup_timer_2(T2_DIV_BY_4,19,1);      //16,0 us overflow, 16,0 us interrupt

   enable_interrupts(INT_TIMER2);
   enable_interrupts(GLOBAL);

   while(TRUE){
      if(input_state(PIN_A1)) {
         if(pwmHigh < 124) pwmHigh++;
      }
      
      if(input_state(PIN_A2)) {
         if(pwmHigh > 55) pwmHigh--;
      }
      delay_ms(2);
   }

}
