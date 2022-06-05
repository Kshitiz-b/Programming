#include<iostream>
using namespace std;
class book
{
    private:
    string author;
    int pages;
    float price;
    
    public:
    void readdata(string ath, int pg, float pr)
    {
        author=ath;
        pages=pg;
        price=pr;
    
    }
    void displaydata()
    {
        cout<<"\n The Book details are:";
        cout<<author<<"\t"<<pages<<"\t"<<price;
        
    }    
    
};

int main()
{
    book java; 
    
    java.readdata("naga",500,1000);
    java.displaydata();
    
    book cpp;
    cpp.readdata("raja",100,2000);
    cpp.displaydata();
    
    return 0;
}