#include<stdio.h>
#include<math.h>

int main(){

double x1, x2, x3, y1, y2, y3;
double area;

printf("Enter three points for a triangle: ");
scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

area = (0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));

printf("The area of the triangle is %0.01lf", area);

return 0;

}
