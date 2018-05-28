#include <stdio.h>
#include<stdlib.h>
void shell(int array[], int n)
{
	int i, j, k, tmp;
	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
		{
			for(k = j - i; k >= 0; k = k - i)
			{
			        if (array[k+i] >= array[k])
				{
					break;
				}
				else
				{
					tmp = array[k];
					array[k] = array[k+i];
					array[k+i] = tmp;
				}
			}
		}
	}
}


int main()
{
	int i,  n;
	scanf("%d", &n);
	int*mass=(int*)malloc(n*sizeof(int));
	for (i=  0 ; i < n; i++)
	{
		scanf("%d", &mass[i]);
	}
	shell(mass, n);
	for (i = 0; i < n; i++)
	printf("%d ", mass[i]);
	free(mass);
	printf("\n");
	return 0;
}
