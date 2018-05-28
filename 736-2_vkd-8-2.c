#include<stdio.h>
#include<stdlib.h>

void swap (int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void Heap(int a[], int n)
{
	int sh=0,i,b=0;
	while (1)
	{
		b = 0;
		for (i = 0; i < n; ++i)
		{
			if (i*2 + 2 + sh < n)
			{
				if (a[i+sh] > a[i*2 + 1 + sh] || a[i + sh] > a[i*2 + 2 + sh])
				{
					if (a[i*2+1+sh] < a[i*2+2+sh])
					{
						swap (&a[i+sh], &a[i*2+1+sh]);
						b = 1;
					}
					else if (a[i*2+2+sh] < a[i*2+1+sh])
					{
						swap (&a[i+sh],&a[i*2+2+sh]);
						b = 1;
					}
				}
			}
			else if (i * 2 + 1 + sh < n)
			{
				if (a[i+sh] > a[i*2+1+sh])
				{
					swap (&a[i+sh], &a[i*2+1+sh]);
					b=1;
				}
			}
		}
		if (!b) sh++;
		if (sh+2==n)
		break;
	}
}

int main()
{
	int n, i;
	scanf("%d",&n);
	int *mass = (int*)malloc(n * sizeof(int));
	for ( i = 0; i <n; i++)
	{
		 scanf("%d", &mass[i]);
	}
	Heap(mass,n);
	for (i = 0; i < n; ++i)
	{
		printf ("%i%c", mass[i], (i!=n-1)?' ':'\n');
	}
	free(mass);
	printf("\n");
	return 0;
}
