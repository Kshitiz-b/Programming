#include<stdio.h>
int main(){
	int n, i=1;
	double miles, km;
	
	scanf("%d", &n);
	printf("Miles	Kilometers\n");
	
	while(i<=n){
		miles = i;
		km = i*1.609;
		printf("%lf\t%lf\n", miles, km);
		i++;
	}
	
	
	return 0;
}
