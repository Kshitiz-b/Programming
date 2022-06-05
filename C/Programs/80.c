#include<stdio.h>

struct student
{
    char name[20];
    int age;

};
void display(struct student *ptr)
{
    // arrow(->) operator used tor access members of a structure using its pointer

    strcpy(ptr->name, "bhar");
    ptr->age = 46;
}

int main()
{
    // Structures - functions and pointers 
    // Structure to function is similar to primitive data types 
    //

    
    struct student ksh = {"kshitiz", 34};

    printf("\nThe student details before function call: ");
    printf("\n%s", ksh.name);
    printf("\n%d", ksh.age);
    
    display(&ksh);
        
    printf("\nThe student details after function call: ");
    printf("\n%s", ksh.name);
    printf("\n%d", ksh.age);

    return 0;
}