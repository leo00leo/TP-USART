#include "stm32f103xb.h"
#include "clk.h"
#include "usart.h"

int main(void){
    clock_72MHz();
    usart_init(USART1, 9600);

    while(1){
        usart_send_char(USART1, 'A')
    }
}