#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
	int data;
	struct node *next;
   	struct node *prev;
} node;
 
typedef node *list;
typedef enum {false, true} bool;
list head=NULL;
list tail=NULL;
 
int init (list *root)
{ 
	(*root)=NULL;
	return 1;
}
 
int destroy(list *root)
{   
   	list x,y;
   	x=*root;
   	y=*root;
	while (x!=NULL)
	{
		y=x->next;
		free(x);
		x=y;
	}
	*root=NULL;
	return 1;
}
 
 
bool isEmpty(list root)
{ 
   	if (root==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
list find(list root, int value)
{
   	list tmp=root;
	while(tmp!=NULL)
	{
		if(tmp->data==value)
		{
			return tmp;
		}
		tmp=tmp->next;
	}
}
           
int append(list* lst, int value)
{   
	if ((*lst)==NULL)
	{
		list tmp=(list)malloc(sizeof(node));
		tmp->next=NULL;
		tmp->data=value;
		tmp->prev=NULL;
		head=tmp;
		tail=tmp;
		return 1;
	}
	list tmp=malloc(sizeof(node));
	tmp->data=value;
	tmp->prev=(*lst);
	if ((*lst)==tail)
        {
		tmp->next=NULL;
		((*lst)->next)=tmp;
		tail=(*lst)->next;
	}
	else
        {
            tmp->next=((*lst)->next);
            ((*lst)->next)->prev=tmp;
            ((*lst)->next)=tmp;
        }
	return 1;
}
       
int prepend(list* lst, int value)
{   
	if ((*lst)==NULL);
        {
		list tmp=(list)malloc(sizeof(node));
		tmp->next=NULL;
		tmp->data=value;
		tmp->prev=NULL;
		head=tmp;
		tail=tmp;
		return 1;
	}
	list tmp=malloc(sizeof(node));
	tmp->data=value;
	tmp->next=(*lst);
	if((*lst)==head)
        {
		tmp->prev=NULL;
		(*lst)->prev=tmp;
		head=(*lst)->prev;
        }
	else
        {
		tmp->prev=(*lst)->prev;
		((*lst)->prev)->next=tmp;
		(*lst)->prev=tmp;
        }
        return 1;
}
 
int remoov(list *lst)
{
	list x;
        x=(*lst);
	if((*lst)==head)
	{
		((x)-> next) -> prev = NULL;
		head = (x -> next);
		free((x));
	}
	else if ((x)== tail)
	{
		((x) -> prev) -> next = NULL;
		tail = ((x)-> prev);
		free((x));
	}
	else
	{
		((x)-> next) -> prev = ((x) -> prev);
		((x)-> prev) -> next = ((x)-> next);
		free((x));
	}
	return 1;
}

int print(list *lst)
{
	while((*lst)!=NULL)
        {
		printf("%d", (*lst)->data);
		printf(" ");
		lst=&((*lst)->next);
        }
	printf("\n");
	return 1;
}

int remoov_k(list *lst, int k)
{
	list tmp;
	int q=1;
	tmp=(*lst);
	while(true)
	{
		if(k==q)
		{
			remoov(&tmp);
			break;
		}
		(tmp)=(tmp)->next;
		q=q+1;
	}
	return 1;
}
 
int main()
{
	init(&head);
	int a,b,i, n, k, m, c, d,data;
	list tp;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &data);
		append(&tail,data);
	}
	print(&head);

	scanf ("%d", &k);
	remoov_k(&head, k);
	print(&head);

	scanf("%d", &m);
	tp=head;
	while (1)
	{
		if((tp->data)==m)
		{
			remoov(&tp);
			break;
		}
		tp-tp->next;
	}
	tp=NULL;
	print(&head);

	scanf("%d",&a);
	scanf("%d",&b);
	tp=head;
	for (i=1; i<(a); i++)
	{
		tp=(tp->next);
	}
	append(&tp, b);
	tp=NULL;
	print(&head);

	scanf("%d", &c);
	scanf("%d", &d);
	tp=head;
	for (i=1; i<(c-1); i++)
	{
		tp = (tp -> next);
	}
	append (&tp, d);
	tp = NULL;
	print (&head);
	destroy(&head);
	return 0;
}
