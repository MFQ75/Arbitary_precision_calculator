#include "inverted.h"

int sub(long num1,long num2,Dlist *tail1,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
	int carry = 0,flag =1;
	while(tail1 || tail2)
	{
		int data1,data2;
		if(num1 > num2)	
		{
			if(tail1 != NULL)
			{
				data1 = tail1->data;
				tail1 = tail1->prev;
			}
			else
				data1 = 0;
			if(tail2 != NULL)
			{
				data2 = tail2->data;
				tail2 = tail2->prev;
			}
			else
				data2 = 0;
		}
		else if(num1 < num2)
		{
			if(tail2 != NULL)
			{
				data1 = tail2->data;
				tail2 = tail2->prev;
			}
			else
				data1 = 0;
			if(tail1 != NULL)
			{
				data2 = tail1->data;
				tail1 = tail1->prev;
			}
			else
				data2 = 0;
		}
		else
		{
			Dlist *new = malloc(sizeof(Dlist));
			if(new == NULL)
				return FAILURE;
			new->data = 0;
			new->prev = NULL;
			new->next = NULL;

			*head3 = new;
			*tail3 = new;
			return SUCCESS;
		}
		if(carry)
		{
			if(data1 == 0)
			{
				data1 = 9;
				carry = 1;
				flag = 0;
			}
			else
			{
			data1 = data1 - 1;
			flag = 1;
			}
		}
		if(data1 < data2)
		{
			data1 = data1 + 10;
			carry = 1;
		}
	        else 
		{
			if(flag)
		carry = 0;
		}

		int data = data1 - data2;
		Dlist *new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;
		new->prev = NULL;
		new->data = data;
		new->next = NULL;

		if(*head3 == NULL)
		{
			*head3 = new;
			*tail3 = new;
		}
		else
		{
			(*head3)->prev = new;
			new->next = *head3;
			*head3 = new;
		}
	}
}
