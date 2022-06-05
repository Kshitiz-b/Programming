#include<iostream>
using namespace std;
class book
{
    private:
    string author;
    int pages;
    float price;
    
    public:
    // constructor - function used for initialization for object
    // its name is same as class name, no return data type, it should be under public
    // it is automatically executed whenever an object created for that class
    // parametrized constructor
    book(string ath, int pg, float pr)
    {
        author=ath;
        pages=pg;
        price=pr;
    }

/*    void readdata(string ath, int pg, float pr)
    {
        author=ath;
        pages=pg;
        price=pr;
    
    }
*/
    void displaydata()
    {
        cout<<"\n The Book details are:";
        cout<<author<<"\t"<<pages<<"\t"<<price;
        
    }    
    
};

int main()
{
    book java("naga",500,1000); 
    
    //java.readdata("naga",500,1000);
    java.displaydata();
    
    book cpp("raja",100,2000);
    //cpp.readdata("raja",100,2000);
    cpp.displaydata();
    
    return 0;
}