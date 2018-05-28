#include <stdlib.h>
#include <stdio.h>

void Hoare(int array[], int first, int last)
{
	int i = first, j = last, x =array[(first + last) / 2], tmp;
	do
	{
		while (array[i] < x)
		{
			i++;
		}
		while (array[j] > x)
		{
			j--;
		}
		if(i <= j)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			i++;
			j--;
		}
	}
	while (i <= j);
	{
		if (i < last)
		{
			Hoare(array, i, last);
		}
	}
	if (first < j)
	{
		Hoare(array, first, j);
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
	Hoare(mass,0,n-1);
	for ( i = 0; i <n; i++)
	{
		printf("%d",mass[i]);
		printf(" ");
	}
	free(mass);
	printf("\n");
	return 0;
}
