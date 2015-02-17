/*******************************************************************************************
* Programmer: Dan Ekiss                                                                    *
* Class: Cpt S 122, Spring 2015, Section 9                                                 *
* PA #3                                                                                    *
* Date: February 16, 2015                                                                  *
* Description: Evaluation of Infix Expressions Using Stacks					               *
*******************************************************************************************/
/*
Write a program to evaluate infix expressions. An infix expression looks like the following:
          9 * (5 - 4) + 2 / 6
This program must first convert the infix expression to a postfix expression, and then evaluate the postfix expression. A postfix expression for the above infix expression looks like the following:
          9 5 4 - * 2 6 / +
For this assignment you will need to implement and apply one stack to convert from infix to postfix, and implement and apply a second stack to evaluate the postfix expression.
Please complete exercises 12.12 and 12.13 form your Deitel & Deitel C How to Program textbook. These exercises provide you with the algorithms required to perform the correct conversions and evaluations. Create a single program only, which combines both exercises. Also, be sure to allow the user to continue to enter infix expressions until they want to quit the program.
BONUS: 
Provide appropriate test cases and drivers for each function in your stack application to receive up to 10 bonus points. For an additional 10 points allow for your program to accept multi-digit operands and unary sign operators (+ and -).
*/


#include "header.h"

int main (void)
{
	char infix[MAX_CHARS] = {'\0'}, postfix[MAX_CHARS] = {'\0'};

	int postfix_outcome = 0;

	printf("Enter an expression in infix notation: ");

	gets(infix);

	postfix_conversion(infix, postfix);

	printf("Resultant postfix expression: %s\n", postfix);

	postfix_outcome = eval_expr (postfix);

	printf("Postfix expression computated to: %d\n", postfix_outcome);

	return 0;
}
