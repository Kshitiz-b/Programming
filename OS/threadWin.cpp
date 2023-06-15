#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

DWORD WINAPI ProcessFile(LPVOID lpParam) {
    string* filename = static_cast<string*>(lpParam);
    // File processing code
    cout << endl << "Processing file: " << *filename << endl;
    // ... Perform operations on the file
    delete filename; // Deallocate dynamic memory
    return 0;
}

int main() {
    vector<string> files = { "file1.jpg", "file2.jpg", "file3.jpg", "file4.jpg" };

    vector<HANDLE> threads;
    for (const auto& file : files) {
        string* filename = new string(file); // Allocate dynamic memory for each filename
        HANDLE hThread = CreateThread(NULL, 0, ProcessFile, filename, 0, NULL);
        if (hThread == NULL) {
            cerr << "Failed to create thread." << endl;
            return 1;
        }
        threads.push_back(hThread);
    }

    // Wait for all threads to finish
    WaitForMultipleObjects(static_cast<DWORD>(threads.size()), threads.data(), TRUE, INFINITE);

    // Clean up
    for (const auto& hThread : threads) {
        CloseHandle(hThread);
    }

    return 0;
}
