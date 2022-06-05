#include<stdio.h>
void myname(char a[][20])
{
	int i;
	for(i=0;i<2;i++){
		printf("My name is: %s \n", a[i]);
	}
	
}

int main(void){
	
	
	char name[20][20] = {"Kshitiz", "Bhargava"};
	
	myname(name);
	

	return 0;
}
