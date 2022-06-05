#include<stdio.h>
int main(){
	
	// Iterative or Loop statements
	// Sequence(1) and selection(0/1)
	// Loop - some part of the code to be executed more than once repetitively(>=0)
	// while loop, do-while, for
	// while and for are same working mechanism but its syntactical structure is different
	// do-while is different from while/for
	// loop = three components - initialization, condition, inc/dec
	
	int i=-21, j=1;
	while(i<-11 && j<=10){
		printf("This is example for While Loop = %d \t %d\n",  i, j);
		i++;
		j++;
	}
	
	
	printf("Using for loop\n");
	
	for(i=-21, j=1;i<-11, j<=10;i++, j++)
	{
		printf("This is example for For Loop = %d \t %d\n",  i, j);
	}
	
	
	printf("Using Do-While Loop\n");
	i=-21; j=1;
	do
	{
		printf("This is example for Do-While Loop = %d \t %d\n",  i, j);
		i++; j++;
	}while(i<-11 && j<=10);
	
	return 0;
}
