#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) 			REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)			REG&=(~(1<<BIT))
#define TGL_BIT(REG,BIT)			REG^=(1<<BIT)
#define GET_BIT(REG,BIT)			((REG>>BIT)&1)
#define ASSIGN_BIT(REG,BIT,VAL)		(REG=(REG&(~(1<<BIT)))|(VAL<<BIT))


#endif   /*BIT_MATH*/




