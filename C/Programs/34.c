#include<stdio.h>
int main(){
	
	int i=1;
	while(i<=10)
	{
		i++;
		if(i==6)
			continue;	
				
		printf("This is While Loop= %d\n", i);
			
	}
	
	return 0;
}
