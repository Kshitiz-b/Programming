#include <iostream>
using namespace std;
int main()
{
    int n;
    int critical_section = -1; // -1 means no proccess in critical section
    cout << "Enter Proccesses Count: ";
    cin >> n;
    int binary_semaphore[n];
    for (int i = 0; i < n; i++)
    {
        binary_semaphore[i] = 0; // Intial Semaphore = 0
    }
    for (int i = 0; i < n; i++)
    {
        binary_semaphore[i] = 1; // 1 means entered the critical section
        cout << "\nProccess " << i + 1 << " enters the Critical Section" << endl;
        cout << "Remaining Proccess\t  Semaphore\n";
        cout << "--------------------------------------------\n";
        for (int j = i; j < n; j++)
        {
            cout << "Process " << j + 1 << "\t\t\t" << binary_semaphore[j] << endl;
        }
    }
    critical_section = -1;
    cout << "\nCritical Section is Now Empty\nAll Process have been executed";
    return 0;
}
