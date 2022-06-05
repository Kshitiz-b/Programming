#include<stdio.h>
// error
int main(){
	
	int n;
	double marks[n];
	char names[n];
	int i;
	
	printf("Enter the number of Students: ");
	scanf("%d", &n);
	
	printf("Enter the names of %d students: \n", n);	
	for(i=0;i<n;i++){
		scanf("%s", names);
	}
	
	printf("\n");
	printf("Enter the marks of %d students: \n", n);
	for(i=0;i<n;i++){
		scanf("%lf", &marks[i]);
	}
	printf("\n");
	
	for(i=0;i<n;i++){
		printf("%c  ", names[i]);
		
	}
	
	for(i=0;i<n;i++){
		printf("%lf", marks[i]);
	}

	printf("\n");
	
	printf("\n");
	
	return 0;
}
