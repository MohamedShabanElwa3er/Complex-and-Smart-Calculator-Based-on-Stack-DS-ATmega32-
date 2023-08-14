/*
 * CALC_s32erface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: Mohamed
 */

#ifndef HAL_CALCULATOR_CALC_s32ERFACE_H_
#define HAL_CALCULATOR_CALC_s32ERFACE_H_

#include "STD.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "CALC_Config.h"



#define MAX_EXPR_SIZE 100
s8 infix[MAX_EXPR_SIZE];
struct Stack* createStack(unsigned capacity);
s32 isEmpty(struct Stack* stack);
s32 peek(struct Stack* stack);
s32 pop(struct Stack* stack);
void push(struct Stack* stack, s32 op);
s32 evaluatePostfix(s8* exp);
s32 precedence(s8 operator);
s32 isOperator(s8 ch);
s8* infixToPostfix(s8* infix);


#endif /* HAL_CALCULATOR_CALC_s32ERFACE_H_ */
