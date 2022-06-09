#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    cout << "Displaying this vector\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        
    }
    cout << endl;
}

int main()
{
    vector<int> vec1; // zero length integer vector
    vector<char> vec2(4); // 4 - element char vector
    vector<char> vec3(vec2); // 4 - element char vector from vec2
    vector<int> vec4(6, 3); // 6-element vector of 3s
    // display(vec1);

    // vec2.push_back('5');
    // display(vec2);

    // vec3.push_back('4');
    // display(vec3);

    display(vec4);
    cout << vec4.size();

    int elements, size = 5;

    return 0;
}