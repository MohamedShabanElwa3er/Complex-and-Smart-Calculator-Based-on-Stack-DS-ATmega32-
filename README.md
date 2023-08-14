# Complex-and-Smart-Calculator-Based-on-Stack-DS-ATmega32-

A Multiple Digit Stack Based Calculator Based On avr architecture using(fares pcb).
-The Project Supports ( Multiple Digits, Precedence on operations (Addition, Subtraction, Multiplication, Division and brackets)).
-Supporting Conversion From Infix To Postfix .

Why Conversion From Infix To Postfix ?!!
-The answer is infix expressions are readable and solvable by humans. We can easily distinguish the order of operators, and also can use the parenthesis to solve that part first during solving mathematical expressions. The computer cannot differentiate the operators and parenthesis easily, that’s why postfix conversion is needed.
-To convert infix expression to postfix expression, we will use the stack data structure. By scanning the infix expression from left to right, when we will get any operand, simply add them to the postfix form, and for the operator and parenthesis, add them in the stack maintaining the precedence of them.
