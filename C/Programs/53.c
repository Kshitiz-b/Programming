#include<stdio.h>
int main(){
	
int lines, i, j;

printf("Enter the number of lines: ");
scanf("%d", &lines);

for(i=1;i<=lines;i++){
	for(j=1;j<=i;j++){
		printf("%d", j);
	}
	printf("\n");
}

for(i=lines;i>=1;i--){
	for(j=1;j<=i;j++){
		printf("%d", j);
	}
	printf("\n");
}


return 0;
}
