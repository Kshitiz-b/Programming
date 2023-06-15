#include <iostream>
#include <vector>
#include <pthread.h>

using namespace std;

void* ProcessFile(void* arg) {
    string* filename = static_cast<string*>(arg);
    // File processing code
    cout << endl << "Processing file: " << *filename << endl;
    // ... Perform operations on the file
    delete filename; // Deallocate dynamic memory
    return NULL;
}

int main() {
    vector<string> files = { "file1.jpg", "file2.jpg", "file3.jpg", "file4.jpg" };

    vector<pthread_t> threads;
    for (const auto& file : files) {
        string* filename = new string(file); // Allocate dynamic memory for each filename
        pthread_t tid;
        if (pthread_create(&tid, NULL, ProcessFile, filename) != 0) {
            cerr << "Failed to create thread." << endl;
            return 1;
        }
        threads.push_back(tid);
    }

    // Wait for all threads to finish
    for (auto& tid : threads) {
        pthread_join(tid, NULL);
    }

    return 0;
}
