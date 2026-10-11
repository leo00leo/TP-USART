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
        GPIOA->CRH&=~(0XF<<PA9*4);
        GPIOA->CRH |=(0XB<<PA9*4);
        GPIOA->CRH&=~(0XF<<PA10*4);
        GPIOA->CRH |=(0XB<<PA10*4);
        USART1->BRR=(PCLK/(16*baudrate));
        valor=(PCLK/(16*baudrate));
        USART1->CR1|=USART_CR1_UE;
        USART1->CR1|=USART_CR1_TE;
        USART1->CR1|=USART_CR1_RE;
        USART1->CR2|=USART_CR2_STOP;
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
        USART2->BRR=(PCLK/(16*baudrate));
        valor=(PCLK/(16*baudrate));
        USART2->CR1|=USART_CR1_UE;
        USART2->CR1|=USART_CR1_TE;
        USART2->CR1|=USART_CR1_RE;
        USART2->CR2|=USART_CR2_STOP;

    }  
    if(USARTx==USART3){
        PCLK=36000000;
        RCC->APB1ENR|=RCC_APB1ENR_USART3EN;
        RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;
        RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
        GPIOB->CRH&=~(0XF<<PB10*4);
        GPIOB->CRH |=(0XB<<PB10*4);
        GPIOB->CRH&=~(0XF<<PB11*4);
        GPIOB->CRH |=(0XB<<PB11*4);
        USART3->BRR=(PCLK/(16*baudrate));
        valor=(PCLK/(16*baudrate));
        USART3->CR1|=USART_CR1_UE;
        USART3->CR1|=USART_CR1_TE;
        USART3->CR1|=USART_CR1_RE;
        USART3->CR2|=USART_CR2_STOP;

        
    }   
} 
void usart_send_char(USART_TypeDef * USARTx, uint8_t data){
    if(USARTx==USART1){
        USART1->SR |=USART_SR_TXE;
        char c=USART1->DR;//leer
        USART1->DR='A';//enviar
    }

    if(USARTx==USART2){
        USART2->SR |=USART_SR_TXE;
        char c=USART2->DR;//leer
        USART2->DR='A';//enviar
    }
    if(USARTx==USART3){
        USART3->SR |=USART_SR_TXE;
        char c=USART3->DR;//leer
        USART3->DR='A';//enviar
    }
    
}       
uint8_t usart_receive_char(USART_TypeDef * USARTx){
    if(USARTx==USART1){
    USART1->SR |=USART_SR_RXNE;
    }
    if(USARTx==USART2){
    USART2->SR |=USART_SR_RXNE;
    }
    if(USARTx==USART3){    
    USART3->SR |=USART_SR_RXNE;    
    }    
}