#include<stdio.h> 
int main() 
{ 

// switch
// alternative to else if ladder
// Structure of switch stmt makes us to understand and readability of the increases.
// switch works with only int & Char  data type
// marks 0 to 100
// >=90 = S 90 to 99 - 9 , 10

 

// m>=80 = A

 

char x='a';
switch(x)
{
    case 'a': 
                        
    case 'b': 
                           printf("S\n");
                           break;
    case '4':
                    printf("A\n");
                           break;
    
    case 't':
                    printf("B\n");
                           break;
            
    default:
                       printf("Fail \n");
                       break;
}

 


return 0;
        
}
