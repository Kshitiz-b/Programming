#include<stdio.h>
#include<math.h>

int main(){

// switch
// alternative to else if ladder
// Structure of switch statement makes us understand and readability increases.
// switch statement works with only integer & Char data type

int m;
printf("Enter the marks:");
scanf("%d", &m);
switch(m/10)
{
	case 10:
			
	case 9:
			printf("S\n");
			break;
	case 8:
			printf("A\n");
			break;
	case 7:
			printf("B\n");
			break;
	case 5:
			printf("C\n");
			break;
	case 6:
			printf("D\n");
			break;						
	default:
			printf("Fail\n");
			break;
			
}
return 0;

}
