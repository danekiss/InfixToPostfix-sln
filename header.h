#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHARS 100

typedef enum boolean Boolean;

enum boolean
{
	FALSE, 
	TRUE
};


struct stack_Char
{
	char data;
	struct stack_Char *next_ptr;
}; // Used with the conversion from infix to postfix

typedef struct stack_Char Stack_Char;

typedef Stack_Char * char_ptr;

void postfix_conversion(char infix[], char postfix[]); // Convert the infix expression to postfix notation.
int is_operator(char ch); // Determine if c is an operator
int precedence(char first_operator, char second_operator); // Evaluate precedence of each operator.
	                                               
char_ptr make_node(char value);
void push(char_ptr *top_ptr, char value); 
void print_char(char_ptr top_ptr); 
char pop(char_ptr *top_ptr); 
char head_stack(char_ptr top_ptr); // Returns the contents at the top of the stack 
int is_empty2(char_ptr top_ptr); 


 struct stackNodeInt
{
	int data;
	struct stackNodeInt *next_ptr;
}; 

typedef struct stackNodeInt StackNodeInt;
typedef StackNodeInt * int_ptr;

// Evaluates only the postfix expression.
int eval_expr(char *expr);
int calculate(int operator_1, int op2, char first_operator); 

int_ptr int_node(int value);
void print_int(int_ptr top_ptr); 
void push_int(int_ptr *top_ptr, int value); 
int pop_int(int_ptr *top_ptr); 
// Check if the stack is empty.
int is_empty1(int_ptr top_ptr); 


#endif
