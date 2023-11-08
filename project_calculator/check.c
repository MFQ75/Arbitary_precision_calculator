#include "inverted.h"

int read_and_validate(char *argv[],Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2)
{
	for(int i=0; argv[1][i] ; i++)
	{
		Dlist *new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;
		char ch = argv[1][i];
		new->data = atoi(&ch);
		new->prev = NULL;
		new->next = NULL;

		if(*head1 == NULL)
		{
			*head1 = new;
			*tail1 = new;
		}
		else
		{
			(*tail1)->next = new;
			new->prev = *tail1;
			*tail1 = new;
		}
	}
	for(int i=0; argv[3][i] ; i++)
	{
		Dlist *new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;
		char ch = argv[3][i];
		new->data = atoi(&ch);
		new->prev = NULL;
		new->next = NULL;

		if(*head2 == NULL)
		{
			*head2 = new;
			*tail2 = new;
		}
		else
		{
			(*tail2)->next = new;
			new->prev = *tail2;
			*tail2 = new;
		}
	}
	return SUCCESS;
}
