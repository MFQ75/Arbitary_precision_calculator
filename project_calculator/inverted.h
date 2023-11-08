#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FAILURE 0
#define SUCCESS 1
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

//function prototype for storing the numbers in linked list
int read_and_validate(char *[],Dlist **,Dlist **,Dlist **,Dlist **);

//function to add the number
int add(Dlist *,Dlist *,Dlist *,Dlist *,Dlist **,Dlist **);

//function prototype to sub the number
int sub(long num1,long num2,Dlist *tail1,Dlist *tail2,Dlist **head3,Dlist **tail3);

int mul(Dlist *tail1,Dlist *tail2,Dlist **head3,Dlist **tail3);

int div_no(Dlist *tail1,Dlist *tail2,Dlist **head3,Dlist **tail3,Dlist **head4,Dlist **tail4);

int count_nodes(Dlist *temp);
#endif
