#include<stdio.h>

int main(){
	
	int check;
	double rate, RMB, dollar;

	printf("Enter the exchange rate from dollars to RMB: ");
	scanf("%lf", &rate);
	
	printf("Enter 0 ot convert dollars to RMB and 1 vice versa: ");
	scanf("%d", &check);
	
	
	if(check==0){
		printf("Enter the dollar amount: ");
		scanf("%lf", &dollar);
		
		RMB = dollar*rate;
		printf("$%lf is %lf yuan", dollar, RMB);
	}
	
	else if(check==1){
		printf("Enter the RMB amount");
		scanf("%lf", &RMB);
		
		dollar = RMB/rate;
		printf("%lf yuan is $%lf", RMB, dollar);
	}
	
	else
	printf("Wrong Input");
	return 0;
}
