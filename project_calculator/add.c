#include "inverted.h"


int add(Dlist *head1,Dlist *head2,Dlist *tail1,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
	int carry = 0;
	while(tail1 || tail2)
	{
		int t1_data,t2_data;
		if(tail1 != NULL)
		{
			t1_data = tail1->data;
			tail1 = tail1->prev;
		}
		else
		{
			t1_data = 0;
		}
		if(tail2 != NULL)
		{
			t2_data = tail2->data;
			tail2 = tail2->prev;
		}
		else
		{
			t2_data = 0;
		}
		int data = (t1_data + t2_data)+carry;
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
		new->data = data;
		new->prev = NULL;
		new->next = NULL;
		if(*head3 == NULL)
		{
			*head3 = new;
			*tail3 = new;
		}
		else
		{
			new->next = *head3;
			(*head3)->prev = new;
			*head3 = new;
		}
	}
	if(carry)
	{
		Dlist *new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;
		new->data = carry;
		new->prev = NULL;
		new->next = NULL;
		new->next = *head3;
		(*head3)->prev = new;
		*head3 = new;
	}
	return SUCCESS;
}
