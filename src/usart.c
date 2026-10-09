#include "stm32f103xb.h"
#include "usart.h"
#define PA2 7
#define PA3 4
#define PA9 2 
#define PA10 3
#define PB10 5 
#define PB11 6
int volatile valor;
int volatile PCLK;
void usart_init(USART_TypeDef * USARTx, uint32_t baudrate){
    if(USARTx==USART1){
        PCLK=72000000;
        RCC->APB2ENR|=RCC_APB2ENR_USART1EN;
        RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
        GPIOA->CRL&=~(0XF<<PA9*4);
        GPIOA->CRL |=(0XB<<PA9*4);
        GPIOA->CRL&=~(0XF<<PA10*4);
        GPIOA->CRL |=(0XB<<PA10*4);
        USART_BRR_DIV_Mantissa=0d27
        USART1->BRR=(PCLK/(16*baudrate));
        valor=(PCLK/(16*baudrate));
        USART1->CR1|=USART_CR1_UE;
        USART1->CR1|=USART_CR1_TE;
        USART1->CR1|=USART_CR1_RE;
        
    }
    if(USARTx==USART2){
        PCLK=360000000;
        RCC->APB1ENR |=RCC_APB1ENR_USART2EN;
        RCC->APB2ENR |=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
        GPIOA->CRL&=~(0XF<<PA9*4);
        GPIOA->CRL |=(0XB<<PA9*4);
        GPIOA->CRL&=~(0XF<<PA10*4);
        GPIOA->CRL |=(0XB<<PA10*4);
        USART2->BRR=(PCLK/(16*baudrate));
        valor=(PCLK/(16*baudrate));
    }
    if(USARTx==USART3){
        PCLK=360000000;
        RCC->APB1ENR|=RCC_APB1ENR_USART2EN;
        RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
        GPIOA->CRL&=~(0XF<<PB10*4);
        GPIOA->CRL |=(0XB<<PB10*4);
        GPIOA->CRL&=~(0XF<<PB11*4);
        GPIOA->CRL |=(0XB<<PB11*4);
        USART3->BRR=(PCLK/(16*baudrate));
        valor=(PCLK/(16*baudrate));
    }    

}