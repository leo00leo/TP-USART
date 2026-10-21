#include "stm32f103xb.h"
#include "usart.h"
#define PA2 7
#define PA3 4
#define PA9     9 
#define PA10    10
#define PB10 5 
#define PB11 6
int   mantissa;
int   fraction;
float valor;
int   PCLK;

void usart_init(USART_TypeDef * USARTx, uint32_t baudrate){
    if(USARTx==USART1){
        PCLK=72000000;
        RCC->APB2ENR|=RCC_APB2ENR_USART1EN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
        GPIOA->CRH&=~(0XF<<(PA9 %8)*4);
        GPIOA->CRH|=(0XB<< (PA9 %8)*4);
        GPIOA->CRH&=~(0XF<<(PA10%8)*4);
        GPIOA->CRH|=(0XB<< (PA10%8) *4);
    }
    if(USARTx==USART2){
        PCLK=360000000;
        RCC->APB1ENR |=RCC_APB1ENR_USART2EN;
        RCC->APB2ENR |=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR |=RCC_APB2ENR_IOPAEN;
        GPIOA->CRL&=~(0XF<<PA2*4);
        GPIOA->CRL |=(0XB<<PA2*4);
        GPIOA->CRL&=~(0XF<<PA3*4);
        GPIOA->CRL |=(0XB<<PA3*4);
    }  
    if(USARTx==USART3){
        PCLK=360000000;
        RCC->APB1ENR|=RCC_APB1ENR_USART3EN;
        RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
        GPIOB->CRH&=~(0XF<<PB10*4);
        GPIOB->CRH |=(0XB<<PB10*4);
        GPIOB->CRH&=~(0XF<<PB11*4);
        GPIOB->CRH |=(0XB<<PB11*4);
    }   
    valor=(PCLK/(16*baudrate));
    mantissa=(valor);
    fraction=((valor-mantissa)*100);
    USARTx->BRR=((mantissa<<4)|(fraction&0xF));
    USARTx->CR1|=USART_CR1_UE;
    USARTx->CR1|=USART_CR1_TE;
    USARTx->CR1|=USART_CR1_RE;
} 
void usart_send_char(USART_TypeDef * USARTx, uint8_t data){
    USARTx->DR=data;//enviar
    /*           0     &      1           */
    while(!(USARTx->SR & USART_SR_TXE));
}       
uint8_t usart_receive_char(USART_TypeDef * USARTx){
    while(!(USARTx->SR & USART_SR_RXNE));
    return USARTx->DR;
}
void usart_send_string(USART_TypeDef *USARTx, char* txt){
    while(*txt){
        usart_send_char(USARTx,*txt);
        txt++;
    }
}
