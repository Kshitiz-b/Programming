#include<stdio.h>
#include<math.h>
int main(){
	double a, b, c, d, r1, r2;
	printf("Enter a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	d = b*b-4*a*c;
	r1 = (-b + sqrt(d))/2*a;
	r2 = (-b - sqrt(d))/2*a;
	
	if(d<0){
		printf("The equation has no real roots");
	}
	else if(d==0)
	printf("The root is %lf", r1);
	
	else
	printf("The roots are %lf and %lf", r1, r2);
	
	return 0;
}
