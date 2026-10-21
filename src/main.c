#include "stm32f103xb.h"
#include "clk.h"
#include "usart.h"

int main(void){
    clock_72MHz();
    usart_init(USART1, 9600);

    usart_send_string(USART1, "manon washed");
}