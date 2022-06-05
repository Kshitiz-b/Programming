#include<stdio.h>
#include<string.h>
int main()
{
	// char data type - String = a collection/group of characters
	// null \0
	
	char name1[10] = {'a', 'b', 'c', '\0'};	// add null character
	
	char name2[10] = "abc";
	
	char name3[45];
	int i=0, count=0;
	
	scanf("%[^\n]s", name3);	// string - & not required
	
		printf("First string is %s\n", name1);
			printf("Second string is %s\n", name2);
	printf("Third string is %s\n", name3);
	
	// length of a string
	while(name3[i]!='\0'){
		count++;
		i++;
	}
	printf("The length is: %d\n", count);
	printf("The length using library function is: %d\n", strlen(name3));
    
    if(strcmp(name1, name2))	// 0 - equal, non-zero - not equal
    {
    	printf("Not Equal");
	}
	else
	printf("Equal");
    return 0;

}
