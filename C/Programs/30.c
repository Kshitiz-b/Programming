#include<stdio.h>
#include<math.h>
int main(){
	int num, x, y;
	printf("Enter the integer: ");
	scanf("%d", &num);
	
	if((num%5==0) && (num%6==0))
	printf("%d is divisible by both 5 and 6", num);
	
	else if(num%5==0)
	printf("%d is divisible by 5 or 6, but not both", num);
	
	else if(num%6==0)
	printf("%d is divisible by 5 or 6, but not both", num);
	
	else
	printf("%d is not divisible by either 5 or 6", num);
	
	return 0;
}
