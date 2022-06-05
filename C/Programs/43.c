#include<stdio.h>

int main(){
	int n=10;
	int num[n], i, j, k;
	printf("Enter ten numbers: \n");
	for(i=0;i<n;i++){
		scanf("%d", &num[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(num[i]==num[j])
			{
				for(k=j;k<n-1;k++)
				{
					num[k] = num[k+1];
				}
				n--;
				j--;
			}	
		}
	}
	for(i=0;i<n;i++)
	printf("\n The distinct numbers are: %d", num[i]);
	
	return 0;
}
