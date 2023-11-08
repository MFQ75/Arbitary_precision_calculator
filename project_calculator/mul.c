#include "inverted.h"

int mul(Dlist *tail1,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
	int carry = 0;
	while(tail1 || tail2)
	{
		int data1,data2;
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

		int data = (data1 + data2) + carry;
		if(data > 9)
		{
			carry = data/10;
			data = data % 10;
		}
		else
			carry = 0;

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
	if(carry)
	{
		Dlist *new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;
		new->prev = NULL;
		new->data = carry;
		new->next = NULL;

		(*head3)->prev = new;
		new->next = *head3;
		*head3 = new;
	}
	return SUCCESS;

}
