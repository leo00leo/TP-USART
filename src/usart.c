#include "stm32f103xb.h"
#include "usart.h"
#define PA2 7
#define PA3 4
#define PA9 2 
#define PA10 3
#define PB10 5 
#define PB11 6
int valor;
int volatile PCLK;
void usart_init(USART_TypeDef * USARTx, uint32_t baudrate){
    if(USARTx==USART1){
        PCLK=720000;
        RCC->APB2ENR|=RCC_APB2ENR_USART1EN;
        RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
        GPIOA->CRL&=~(0XF<<PA9*4);
        GPIOA->CRL |=(0X4<<PA10*4);
        RCC->APB2ENR |RCC_APB2ENR_USART1EN;
        USART1->BRR&~PCLK/(16*baudrate);
}
    if(USARTx==USART2){
        RCC->APB1ENR|=RCC_APB1ENR_USART2EN;
        RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
        GPIOA->CRL&=~(0XF<<PA9*4);
        GPIOA->CRL |=(0XB<<PA10*4);
}
    if(USARTx==USART3){
        RCC->APB1ENR|=RCC_APB1ENR_USART2EN;
        RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
        GPIOA->CRL&=~(0XF<<PB10*4);
        GPIOA->CRL |=(0XB<<PB11*4);
}    

}