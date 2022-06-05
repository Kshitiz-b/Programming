#include<stdio.h>
int main(){
int i, n=2;
int list1[n], list2[n];
int identical=0;


printf("Enter listl:\n");
for (i=0;i<n;i++){
	scanf("%d", &list1[i]);
}

printf(" \nEnter list2:\n");

for(i=0;i<n;i++){
scanf("%d", &list2[i]);
}
for(i=0;i<n;i++){
	if(list1[i]!=list2[i]){
		identical == 0;
		break
	}
	else{
		identical = 1;
	}
}

if(identical == 0)
{
	printf("not identical");
}
else{
	printf("identical");
}
return 0;
}

