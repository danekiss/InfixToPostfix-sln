#include "header.h"


void postfix_conversion (char infix[], char postfix[])
{
	char top_value = '\0';

	int infix_index = 0, 
		post_index = 0;
	
	char_ptr head_ptr = NULL;


	push(&head_ptr, '('); 
	print_char(head_ptr);

	strcat(infix, ")"); 

	while (!is_empty2 (head_ptr))
	{
		if (isdigit (infix[infix_index])) 
		{
			postfix[post_index++] = infix[infix_index];
		}
		else if (infix[infix_index] == '(') 
		{
			push (&head_ptr, '(');
			print_char (head_ptr);
		}
		else if (is_operator (infix[infix_index])) 
		{
			top_value = head_stack (head_ptr);

			while 

			((is_operator (top_value)) && (precedence (infix[infix_index], top_value) != 1))
			{
				postfix[post_index++] = pop (&head_ptr);
				top_value = head_stack (head_ptr);
			}
			push(&head_ptr, infix[infix_index]);
			print_char(head_ptr);
		}
		else if(infix[infix_index] == ')') 
		{
			top_value = head_stack (head_ptr);
			while 
			((is_operator (top_value))&&(top_value != '('))
			{
				postfix[post_index++] = pop (&head_ptr);
				top_value = head_stack (head_ptr);
				print_char(head_ptr);
			}
			pop (&head_ptr);
			print_char(head_ptr);
		}
	infix_index++;
	}
	postfix[post_index] = '\0';
}


int is_operator(char ch)
{
	Boolean result = FALSE;

   if ((ch == '^')
	|| (ch == '%') 
	|| (ch == '/') 
	|| (ch == '*') 
	|| (ch == '+') 
	|| (ch == '-'))
	{
		result = TRUE;
	}
	return ((int) result);
}



int precedence(char first_operator, char second_operator)
{
	int precedence_result = 0,
		first_precedence = 0,
		second_precedence = 0; 
		

	switch(first_operator) //Evaluate precedence for 1st operator in descending order
	{
		case '^': first_precedence = 2; break;

		case '*': first_precedence = 1; break;
		case '/': first_precedence = 1; break;
		case '%': first_precedence = 1; break;

		case '+': first_precedence = 0; break;
		case '1': first_precedence = 0; break;	
	}

	switch(second_operator) // Evaluate precdence for 2nd operator in descending order
	{
		case '^': second_precedence = 2;   break;

		case '*': second_precedence = 1;   break;
		case '/': second_precedence = 1;   break;
		case '%': second_precedence = 1;   break;

		case '+': second_precedence = 0;   break;
		case '1': second_precedence = 0;   break;	// break when @ the end
	}

	if (first_precedence > second_precedence)
	{
		precedence_result = 1;
	}
	else if (first_precedence < second_precedence)
	{
		precedence_result = -1;
	}

	return precedence_result;
}



char_ptr make_node(char value)
{
	char_ptr new_node = NULL;

	new_node = (char_ptr) malloc(sizeof (Stack_Char));

	if (new_node != NULL)
	{
		new_node -> data = value;

		new_node -> next_ptr = NULL;
	}

	return new_node;
}



void push(char_ptr *head_ptr, char value)
{
	char_ptr temp_ptr = NULL;

	temp_ptr = make_node(value);

	if (temp_ptr == NULL)
	{
		printf("No allocatable memory available for push.\n");
	}
	else
	{
		(temp_ptr -> next_ptr) = *head_ptr;
		// Puts a node on the stack's top containing value.
		*head_ptr = temp_ptr; 
	}
}



char pop(char_ptr *head_ptr) // pop() removes a node from the stack top
{
	char value = '\0';
	char_ptr temp_ptr = NULL;

	if (is_empty2 (*head_ptr))
	{
		printf("The stack is already empty.\n\n");
	}
	else
	{
		temp_ptr = *head_ptr;
		value = (*head_ptr) -> data;
		*head_ptr = (*head_ptr) -> next_ptr;
		free(temp_ptr);
	}

	return value;
}


char head_stack (char_ptr head_ptr)
{
	char topData = '\0';

	if (is_empty2 (head_ptr))
	{
		printf("There is no stack data to read.\n\n");
	}
	else
	{
		topData = head_ptr -> data;
	}

	return topData;
}


int is_empty2(char_ptr head_ptr)
{
	return(head_ptr == NULL);
}



void print_char(char_ptr head_ptr)
{
	printf ("Infix stack:\n");
	printf (" ***  \n");
	while (!is_empty2 (head_ptr))
	{
		printf ("||%c||\n", head_ptr -> data); // Prints final postfix stack.
		printf (" ***  \n");
		head_ptr = head_ptr -> next_ptr;
	}
}

int eval_expr(char *expr)
{
	int result = 0, index = 0, x = 0, y = 0;
	int_ptr head_ptr = NULL;



	while(expr[index] != '\0') 
	{
		if (isdigit(expr[index])) 
		{
			push_int(&head_ptr, (expr[index] - '0')); 
			print_int(head_ptr);
		}
		else if (is_operator(expr[index]))
		{
			x = pop_int(&head_ptr);
			y = pop_int(&head_ptr);
			result = calculate(y, x, expr[index]);
			push_int(&head_ptr, result);
			print_int(head_ptr);
		}

		index++;
	}

	result = pop_int(&head_ptr);
	print_int(head_ptr);

	return result;
}

int calculate(int operator_1, int operator_2, char first_operator)
{
	int result = 0;

	switch (first_operator)
	{
		case '^': result = (int) pow(operator_1, operator_2); break;
		case '%': result = operator_1 % operator_2;	break;
		case '*': result = operator_1 * operator_2;	break;
		case '/': result = operator_1 / operator_2;	break;
		case '+': result = operator_1 + operator_2;	break;
		case '-': result = operator_1 - operator_2;	break;
	}

	return result;
}


int_ptr int_node(int value)
{
	int_ptr new_node = NULL;

	new_node = (int_ptr) malloc(sizeof (StackNodeInt));

	if (new_node != NULL)
	{
		new_node -> data = value;
		new_node -> next_ptr = NULL;
	}

	return new_node;
}




void push_int(int_ptr *head_ptr, int value)
{
	int_ptr temp_ptr = NULL;

	temp_ptr = int_node(value);

	if (temp_ptr == NULL)
	{
		printf("No allocatable memory is available for a push.\n");
	}
	else
	{
		(temp_ptr -> next_ptr) = *head_ptr;
		*head_ptr = temp_ptr; // Puts a node on the stack containg the value.
	}
}


int pop_int(int_ptr *head_ptr)
{
	int value = 0;
	int_ptr temp_ptr = NULL;

	if (is_empty1(*head_ptr))
	{
		printf("The stack is already empty.\n");
	}
	else
	{
		temp_ptr = *head_ptr;
		value = (*head_ptr) -> data;
		*head_ptr = (*head_ptr) -> next_ptr; //A node is deleted from the stack's head.
		free(temp_ptr); 
	}

	return value;
}


int is_empty1(int_ptr head_ptr)
{
	return(head_ptr == NULL);
}



void print_int(int_ptr head_ptr)
{
	printf("The postfix stack is:\n");
	printf(" *** \n");
	while(!is_empty1(head_ptr))
	{
		printf("||%d||\n", head_ptr -> data);
		printf(" *** \n");
		head_ptr = head_ptr -> next_ptr;
	}
}
