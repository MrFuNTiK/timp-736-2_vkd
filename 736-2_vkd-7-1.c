#include <stdio.h>
#include <stdlib.h>


void comb(int array[], int n)
{
	if (array && n)
	{
		int  h = n, i;
		int s = 1;
		while (h > 1 || s)
		{
			if (h > 1)
			h /= 1.24733;
			s = 0;
			for (i = 0; i + h < n; ++i)
			{
				if (array[i + h] <array[i])
				{
					int tmp;
					tmp = array[i];
					array[i] = array[i + h];
					array[i + h] = tmp;
					s = 1;
				}
			}
		}
	}
}


int main()
{
	int n,i;
	scanf("%d",&n);
	int *mass = malloc(sizeof(int[n]));
	for ( i = 0; i <n; i++)
	{
		scanf("%d", &mass[i]);
	}
	comb(mass,n);
	for ( i = 0; i <n; i++)
	{
		printf("%d",mass[i]);
		printf(" ");
	}
	free(mass);
	printf("\n");
	return 0;
}
