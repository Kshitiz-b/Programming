#include <iostream>
#include <cstring>
using namespace std;

class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string s, float r)
    {
        title = s;
        rating = r;
    }

    virtual void display() = 0; // do nothing function --> pure virtual funcitons
    
};

class CWHVideo : public CWH
{
    int length;

public:
    CWHVideo(string s, float r, int vl) : CWH(s, r)
    {
        length = vl;
    }

    void display()
    {
        cout << "\nThis is an amazing video with title " << title << endl;
        cout << "This video has rating " << rating << " out of 5 stars" << endl;
        cout << "The length of this video is " << length << " minutes" << endl;
    }
};

class CWHText : public CWH
{
    int words;

public:
    CWHText(string s, float r, int wc) : CWH(s, r)
    {
        words = wc;
    }

    void display()
    {
        cout << "\ntitle " << title << endl;
        cout << "rating " << rating << " out of 5 stars" << endl;
        cout << "No. of words is " << words << " words\n" << endl;
    }
};

int main()
{
    string title;
    float rating, vlen;
    int words;

    title = "Django tutorial Video";
    vlen = 4.56;
    rating = 4.89;

    CWHVideo djVideo(title, rating, vlen);
    // djVideo.display();

    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;

    CWHText djText(title, rating, words);
    // djText.display();

    CWH *tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;

    tuts[0]->display();
    tuts[1]->display();

    return 0;
}