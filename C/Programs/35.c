#include<stdio.h>
#include<stdlib.h>
int main()
{
    // exit()  exit entire program execution
    
    
    int i=1;
    
    
            printf("This is beginning of while loop\n");
            while(i<=10)
            {
                if(i==6)
                    exit(1); // exit the program
                i++;
                printf("This is i value: %d\n",i);
            }
            printf("This is end of the while loop\n");
    raja: 
            printf("This is end of the Program\n");
    
    
    
    
    return 0;

 

}
