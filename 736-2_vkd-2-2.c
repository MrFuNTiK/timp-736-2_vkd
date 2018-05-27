#include "stdio.h"
int main()
{
	int n, count, x, sum = 0;
	scanf("%d",&count);
	for (n=1; n<=count; n++)
		{
		scanf("%d", &x);
		sum += x*x;
		}
	printf("%d",sum);
	return 0;
}
