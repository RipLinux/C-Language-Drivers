/***************************************/
/******   Author:   Anas  Sayed  *******/
/******   Time:     07/28/2026   *******/
/******   File:     Math    File *******/
/***************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NUM)        REG |=  (1 << (BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)        REG &= ~(1 << (BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)        REG ^=  (1 << (BIT_NUM))
#define GET_BIT(REG,BIT_NUM)       ((REG >> (BIT_NUM)) & 0x01)

#define CIR_SHIFT_L_BIT(REG)        REG = (GET_BIT(REG,7) | (REG << 1))
#define CIR_SHIFT_R_BIT(REG)        REG = ((GET_BIT(REG,0) << 7) | (REG >> 1))

#define SET_NIBBLE(REG,CASE)        REG |=  (0x0F << (4 * (CASE)))
#define CLR_NIBBLE(REG,CASE)        REG &= ~(0x0F << (4 * (CASE)))

#define ASG_NIBBLE(REG,CASE,VALUE) \
REG = ((CASE==0)?((REG&0xF0)|((VALUE)&0x0F)):((REG&0x0F)|(((VALUE)&0x0F)<<4)))

#define SET_PORT(REG)               REG = 0xFF
#define CLR_PORT(REG)               REG = 0x00
#define ASG_PORT(REG,VALUE)         REG = (VALUE)

/* Pastes 8 bits into a 0bXXXXXXXX literal */
#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

/* Wrapper that forces macro-expansion of the arguments (e.g. OUTPUT/INPUT)
   BEFORE they are pasted by CONC_BIT. Operands of ## are NOT expanded on their own. */
#define CONC_BIT_EXPAND(b7,b6,b5,b4,b3,b2,b1,b0) CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* BIT_MATH_H */
