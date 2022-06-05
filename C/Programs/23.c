#include<stdio.h>
#include<math.h>

int main(){
// absolute grading system


double m;
printf("Enter the marks:");
scanf("%lf", &m);
if(m>=90)	//logical operators &&, ||, !
{	printf("S\n");
}
else if(m>=80)
{	printf("A\n");
}
else if(m>=70)
{	printf("B\n");
}
else if(m>=60)
{	printf("C\n");
}
else if(m>=50)
{	printf("D\n");
}
else
{	printf("Fail\n");
}
return 0;

}
