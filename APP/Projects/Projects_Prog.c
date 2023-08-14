
#include "Projects_Interface.h"


int main()
{
	u8 ret=0;                                      // KEYPAD CHARACTER RECEIVER VARIABLE TO RECEIVE KEYPAD CHARACTER
	u8 infix_index=0;                              // to increment the index of the infix array to put the input expression
	u8 lcd_postfix_pos=0;                          // to increment lcd colum position while Printing the expression value
    u8 lcd_infix_pos=0;                            // to increment lcd colum position while adding the expression

	H_KeyPad_Void_KeyPadInit(); // KEYPAD INTIALIZING
	H_Lcd_Void_LCDInit();       // LCD INTIALIZING

	H_Lcd_Void_LCDWriteString(" ENTER EXPRESSION ");
	_delay_ms(250);

	H_Lcd_Void_LCDClear();                         // CLEAR LCD INITIALY
	H_Lcd_Void_LCDGoTo(0, 1);
	H_Lcd_Void_LCDWriteString("IF->:");            // INFIX EXPRESSION ON LCD
	H_Lcd_Void_LCDGoTo(1, 1);
	H_Lcd_Void_LCDWriteString("PF->:");            // POSTFIX EXPRESSION ON LCD
	H_Lcd_Void_LCDGoTo(2, 1);
	H_Lcd_Void_LCDWriteString("R ->:");            // THE EXPRESSION VALUE ON LCD


	while(1){

		ret=H_KeyPad_U8_KeyPadRead();

		if(ret=='1'||ret=='2'||ret=='3'||ret=='4'||ret=='5'||   // IF FUNCTION TO CHECK USER INPUTS
				     ret=='6'||ret=='7'||ret=='8'||ret=='9'||
				     ret=='*'||ret=='/'||ret=='+'||ret=='-'||
					 ret=='('||ret==')')
		{
			H_Lcd_Void_LCDGoTo(0, lcd_infix_pos+6);
			lcd_infix_pos++;
			if(ret=='*'||ret=='/'||ret=='+'||ret=='-')  // IF FUNCTION TO CHECK IF OPERATOR IS ENTERD
			{
				H_Lcd_Void_LCDWriteCharacter(ret);
				infix[infix_index++]=ret;
				infix[infix_index++]=' ';
			}
			else
			{
				infix[infix_index++]=ret;
				H_Lcd_Void_LCDWriteCharacter(ret);
			}
		}

		else if(ret=='=')                // INCASE THE USER END THE EXPRESSION AND WANT THE RESULT
		{
			lcd_postfix_pos++;
			s8* postfix = infixToPostfix(infix);
			H_Lcd_Void_LCDGoTo(1, lcd_postfix_pos+5);
			H_Lcd_Void_LCDWriteString(postfix);
			H_Lcd_Void_LCDGoTo(2, 6);
			H_Lcd_Void_LCDWriteNumber(evaluatePostfix(postfix));

		}
		else
		{

		}

	}


	return 0;
}



