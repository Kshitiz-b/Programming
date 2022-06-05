#include<stdio.h>
#include<math.h>
int main(){
	int num1, num2, num3;
	printf("Enter three integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	if((num3>num2) && (num2>num1))
	printf("%d <= %d <= %d", num1, num2, num3);
	
	else if((num2>num3) && (num3>num1))
	printf("%d <= %d <= %d", num1, num3, num2);
	
	else if((num1>num2) && (num2>num3))
	printf("%d <= %d <= %d", num3, num2, num1);
	
	return 0;
}
