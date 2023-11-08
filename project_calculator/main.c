#include "inverted.h"
int main(int argc,char *argv[])
{
	if(argc != 4)
	{
		printf("Error : Invalid arguments\n");
		printf("Usage : ./a.out 1234 + 1234\n");
	}
	else
	{
		Dlist *head1 = NULL;
		Dlist *head2 = NULL;
		Dlist *head3 = NULL;
		Dlist *tail1 = NULL;
		Dlist *tail2 = NULL;
		Dlist *tail3 = NULL;
		if(!read_and_validate(argv,&head1,&head2,&tail1,&tail2))
			return 1;
		long num1 = atoi(argv[1]);
		long num2 = atoi(argv[3]);
		char *ch = argv[2];
		int n = 1;
		Dlist *temp;
		switch(*ch)
		{
			case '+' : add(head1,head2,tail1,tail2,&head3,&tail3);
				   break;
			case '-' : sub(num1,num2,tail1,tail2,&head3,&tail3);
				   if(num1 < num2)
					   printf("-");
				   break;
			case 'x' : while(tail2)
				   {
					   for(int j=0; j<(tail2->data * n); j++) 
					   {
						   temp = tail3;
						   head3 = NULL;
						   tail3 = NULL;
						   mul(tail1,temp,&head3,&tail3);
					   }
					   n = n * 10;
					   tail2 = tail2->prev;
				   }
				   break;
			case '/' : temp = tail1;
				   Dlist *head4 = NULL, *tail4 = NULL;
				   while(div_no(temp,tail2,&head3,&tail3,&head4,&tail4))
				   {
					   temp = tail4;
					   if(count_nodes(temp) > count_nodes(tail2) || head4->data >= head2->data) 
					   {   
						   head4 = NULL;
						   tail4 = NULL;
					   }
					   else
						   break;
				   }
		}
		temp = head3;
		while(temp)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}
