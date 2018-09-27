
#include <stdio.h>
#include <limits.h>
#include<stdlib.h>


int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int optimalStrategyOfGame(int* arr, int n)
{

	int table[n][n], gap, i, j, x, y, z;

	for (gap = 0; gap < n; ++gap)
	{
		for (i = 0, j = gap; j < n; ++i, ++j)
		{

			x = ((i+2) <= j) ? table[i+2][j] : 0;
			y = ((i+1) <= (j-1)) ? table[i+1][j-1] : 0;
			z = (i <= (j-2))? table[i][j-2]: 0;

			table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
		}
	}

	return table[0][n-1];
}


int main()
{
    int n,i;
    int *arr;
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
	printf("%d", optimalStrategyOfGame(arr, n));

	return 0;
}

