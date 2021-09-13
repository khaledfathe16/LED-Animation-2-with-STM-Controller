#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define RRC_BASE_ADDRESS        0x40021000       //The Reference address

/*Register Addresses*/

#define RCC_CR                 *((u32*)(RRC_BASE_ADDRESS + 0x00))
#define RCC_CFGR               *((u32*)(RRC_BASE_ADDRESS + 0x04)) 
#define RCC_CIR                *((u32*)(RRC_BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR           *((u32*)(RRC_BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR           *((u32*)(RRC_BASE_ADDRESS + 0x010))
#define RCC_AHBENR             *((u32*)(RRC_BASE_ADDRESS + 0x14))
#define RCC_APB2ENR            *((u32*)(RRC_BASE_ADDRESS + 0x18))
#define RCC_APB1ENR            *((u32*)(RRC_BASE_ADDRESS + 0x1C))
#define RCC_BDCR               *((u32*)(RRC_BASE_ADDRESS + 0x20)) 
#define RCC_CSR                *((u32*)(RRC_BASE_ADDRESS + 0x24))



#define RCC_HSI                     0
#define RCC_HSE_CRYSTAL             1
#define RCC_HSE_RC                  2
#define RCC_PLL_HSE_CRYSTAL         3
#define RCC_PLL_HSE_RC              4
#define RCC_PLL_HSI                 5















#endif