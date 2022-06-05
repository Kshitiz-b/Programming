/*Define a structure that can describe a book.
It should have members that include the 
author, publisher, no.of pages, ISBN number, 
price and date of publish. Consider date of 
publish as one of structure with day, 
month and year.do the following tasks:Read 
the data for 10 books. Display the same
find the book details with highest price
display the book details published after the year 2015.*/

#include <stdio.h>

struct dop
{
    int day;
    int month;
    int year;
};

struct books
{
    char author[20];
    char publisher[20];
    int pages;
    char isbn[20];
    float price;
    struct dop d;

};

int main(){

    struct books book[20];
    printf("Enter author name, publisher, no. of pages, ISBN number, price and date of publish: ");

    for(int i=0; i<2;i++)
    {
        scanf("%s", book[i].author);
        scanf("%s", book[i].publisher);
        scanf("%d", &book[i].pages);
        scanf("%s", book[i].isbn);
        scanf("%f", &book[i].price);
        scanf("%d", &book[i].d.day);
        scanf("%d", &book[i].d.month);
        scanf("%d", &book[i].d.year);
    }

    for(int i=0; i<2;i++)
    {
        printf("\n%s", book[i].author);
        printf("\n%s", book[i].publisher);
        printf("\n%d", book[i].pages);
        printf("\n%s", book[i].isbn);
        printf("\n%f", book[i].price);
        printf("\n%d/", book[i].d.day);
        printf("%d/", book[i].d.month);
        printf("%d\n", book[i].d.year);
    }
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(book[i].price > book[j].price)
            {
                printf("MAX PRICE IS %f", book[i].price);
            }
        }
    }

    for(int i=0;i<2;i++)
    {
        if(book[i].d.year > 2015)
        {
            printf("Books Published after 2015 are: %d", book[i].d.year);
        }
    }
    
    return 0;
}