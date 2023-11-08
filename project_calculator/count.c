#include "inverted.h"

int count_nodes(Dlist *temp)
{
	int i = 0;
	while(temp)
	{
		i++;
		temp = temp->prev;
	}
	return i;
}
