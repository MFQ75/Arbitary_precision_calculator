#include "inverted.h"

int count = 1;

int div_no(Dlist *tail1,Dlist *tail2,Dlist **head3,Dlist **tail3,Dlist **head4,Dlist **tail4)
{
	int carry =0,flag = 1;
	while(tail1 || tail2)
	{
		int data1,data2;
		if(tail1 != NULL)
		{
			data1 = tail1->data;
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
			data1 = data1 +10;
			carry = 1;
		}
		else
		{
			if(flag)
			carry = 0;
		}
		int data = data1 - data2;
		if(data == 0)
		{
			if(tail1->prev == NULL && tail1->next == NULL)
			{
				return 0;
			}
			if(tail1->prev == NULL)
			{
			       ++((*tail3)->data);
				return 1;
			}

		}
		tail1 = tail1->prev;
		Dlist *new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;
		new->prev = NULL;
		new->data = data;
		new->next = NULL;
		if(*head4 == NULL)
		{
			*head4 = new;
			*tail4 = new;
		}
		else
		{
			(*head4)->prev = new;
			new->next = *head4;
			*head4 = new;
		}
		if(count > 9 || *head3 == NULL)
		{
			if(count >= 9)
			{
				count = 0;
				Dlist *temp = (*tail3)->prev;
				while(temp)
				{
					if(temp->data > 9)
					{
						++(temp->data);
						return SUCCESS;
					}
					else if(temp->data == 9)
						temp->data = 0;
					temp = temp->prev;
				}
			}
			Dlist *new = malloc(sizeof(Dlist));
			if(new == NULL)
				return FAILURE;
			new->prev = NULL;
			new->data = count;
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
		else if(tail1 == NULL) 
			++((*tail3)->data);
	}
}

