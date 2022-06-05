#include<stdio.h>
void myname(char a[][20])
{
	int i;
	for(i=0;i<5;i++){
		printf("My name is: %s \n", a[i]);
	}
	
}

int main(void){
	
	char name[20][20];
	int i=0;
	printf("Enter 5 names\n");
	
	for(i=0;i<5;i++){
		scanf("%s", name[i]);
	}
	
	myname(name);
	
	
	return 0;
}
