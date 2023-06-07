#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Job {
    int arrival_time;
    int burst_time;
    int remaining_time;
};

void calculateTimes(const vector<Job>& jobs, int quantum_time, vector<int>& turnaround_times, vector<int>& waiting_times) {
    int n = jobs.size();
    vector<int> remaining_times(n, 0);
    vector<int> start_times(n, 0);
    vector<bool> completed(n, false);

    for (int i = 0; i < n; ++i) {
        remaining_times[i] = jobs[i].burst_time;
    }

    queue<int> ready_queue;
    int current_time = 0;
    int completed_jobs = 0;

    while (completed_jobs < n) {
        for (int i = 0; i < n; ++i) {
            if (jobs[i].arrival_time <= current_time && !completed[i]) {
                ready_queue.push(i);
            }
        }

        if (ready_queue.empty()) {
            current_time++;
            continue;
        }

        int job_index = ready_queue.front();
        ready_queue.pop();

        if (remaining_times[job_index] <= quantum_time) {
            current_time += remaining_times[job_index];
            turnaround_times[job_index] = current_time - jobs[job_index].arrival_time;
            waiting_times[job_index] = turnaround_times[job_index] - jobs[job_index].burst_time;
            remaining_times[job_index] = 0;
            completed[job_index] = true;
            completed_jobs++;
        } else {
            current_time += quantum_time;
            remaining_times[job_index] -= quantum_time;
        }

        for (int i = 0; i < n; ++i) {
            if (i != job_index && jobs[i].arrival_time <= current_time && !completed[i]) {
                ready_queue.push(i);
            }
        }

        if (remaining_times[job_index] > 0) {
            ready_queue.push(job_index);
        }
    }
}

void printOutput(const vector<int>& turnaround_times, const vector<int>& waiting_times) {
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int n = turnaround_times.size();

    cout << "Job\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; ++i) {
        cout << (i + 1) << "\t" << turnaround_times[i] << "\t\t" << waiting_times[i] << "\n";
        total_turnaround_time += turnaround_times[i];
        total_waiting_time += waiting_times[i];
    }

    double avg_turnaround_time = static_cast<double>(total_turnaround_time) / n;
    double avg_waiting_time = static_cast<double>(total_waiting_time) / n;

    cout << "\nAverage Turnaround Time: " << avg_turnaround_time << "\n";
    cout << "Average Waiting Time: " << avg_waiting_time << "\n";
}

int main() {
    int num_jobs;
    cout << "Enter the number of jobs: ";
    cin >> num_jobs;

    vector<Job> jobs(num_jobs);
    cout << "Enter arrival time and execution time for each job:\n";
    for (int i = 0; i < num_jobs; ++i) {
        cout << "Job " << (i + 1) << " - Arrival Time: ";
        cin >> jobs[i].arrival_time;
        cout << "Job " << (i + 1) << " - Execution Time: ";
        cin >> jobs[i].burst_time;
        jobs[i].remaining_time = jobs[i].burst_time;
    }

    int quantum_time;
    cout << "Enter the quantum time: ";
    cin >> quantum_time;

    vector<int> turnaround_times(num_jobs, 0);
    vector<int> waiting_times(num_jobs, 0);

    calculateTimes(jobs, quantum_time, turnaround_times, waiting_times);

    cout << "\nPreemptive Round Robin Scheduling Algorithm\n";
    printOutput(turnaround_times, waiting_times);

    return 0;
}
