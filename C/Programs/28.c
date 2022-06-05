#include<stdio.h>
#include<math.h>
int main(){
	double a, b, c, d, e, f, x, y;
	printf("Enter a, b, c, d, e, f: ");
	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
	
	x = (e*d-b*f)/(a*d-b*c);
	y = (a*f-e*c)/(a*d-b*c);
	
	if((a*d-b*c)==0)
	printf("The equation has no solution");
	
	else
	printf("x is %lf and y is %lf", x, y);
	
	return 0;
}
