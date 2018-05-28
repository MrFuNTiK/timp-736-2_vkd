#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef node *queue;

typedef enum {false, true} bool;

queue head = NULL;
queue tail = NULL;

int init(queue *root)
{
	*root = NULL;
	return 1;
}

bool IsEmpty(queue *root)
{
	if (*root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int add (queue *q, int value)
{
	if (*q == NULL)
	{
		queue tmp = (queue)malloc(sizeof(node));
		tmp->data = value;
		tmp->next = NULL;
		head = tmp;
		tail = tmp;
	}
	else
	{
		queue tmp = (queue)malloc(sizeof(node));
		tmp->data = value;
		tmp->next = NULL;
		(*q)->next = tmp;
		tail = tmp;
		}
	return 1;
}

int top(queue *head)
{
	if (head != NULL)
	{
		return((*head)->data);
	}
}

int back(queue *tail)
{
	if (tail != NULL)
	{
		return((*tail)->data);
	}
}

int pop(queue *head)
{
	if (head != NULL)
	{
		queue tmp = (*head)->next;
		int value = (*head)->data;
		free(*head);
		*head = tmp;
		return value;
	}
}

int size (queue *head)
{
	int i = 1;
	if(*head != NULL)
	{
		queue tmp = (*head);
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			i++;
		}
		return i;
	}
	else return 0;
}

int view (queue *head)
{
	if(*head != NULL)
	{
		queue tmp = (*head);
		while (tmp != NULL)
		{
			printf("%d", tmp->data);
			printf(" ");
			tmp = (tmp->next);
		}
	}
}

int destroy (queue *head)
{
	queue x, y;
	x = *head;
	y = x;
	while (x != NULL)
	{
		y = x->next;
		free(x);
		x = y;
	}
	return 1;
}




int main()
{
	init(&head);
	int value, i, n;
	scanf ("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &value);
		add(&tail, value);
	}
	printf("\n");

	printf("%d", top(&head));
	printf("\n");
	
	printf("%d", back(&tail));
	printf("\n");

	view(&head);
	printf("\n");
	
	printf("%d",pop(&head));
	printf("\n");

	view(&head);
	printf("\n");

	printf("%d", size(&head));
	printf("\n");

	destroy(&head);
	return 0;
}
