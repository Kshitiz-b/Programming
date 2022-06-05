#include<stdio.h>
int main(){
	
	// Strings - Character array
	char name[20], school[20], college[20]="VIT", dept[20]={'C', 'S', 'E', '\0'};
	char dept2[20], dept3[20];
	
	
	printf("Enter the string\n");
	scanf("%[^\n]s", name);
	printf("The entire string is: %s\n", name);
	
	getchar();	// read a single character 
	printf("Enter school\n");
	gets(school);	// read a string
	printf("The entered school is:\n");
	puts(school);
	
	printf("The given college is:\n");
	puts(college);
	
	printf("The given department is:\n");
	puts(dept);
	
	//	dept2=dept
	//	two ways - use library function - user defined function
	strcpy(dept2, dept);
	printf("The given second department is:\n");
	puts(dept2);
	
	//	dept3=dept2
	char ch;
	int i;
	while((ch = dept2[i]) != '\0'){
		dept3[i] = ch;
		i++;
	}
	dept3[i]='\0';
	printf("The given third department is:\n");
	puts(dept3);
	
	char gender[20];
	i=0;
	
	while((ch = getchar()) != '\n'){
		gender[i]=ch;
		i++;
	}
	gender[i]='\0';
	printf("The given gender is:\n");
	puts(gender);
	
	return 0;
}
