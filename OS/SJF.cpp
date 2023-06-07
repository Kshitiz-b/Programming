// Non-preemptive
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int arrival_time;
    int execution_time;
};

bool compareJobExecutionTime(const Job &job1, const Job &job2)
{
    return job1.execution_time < job2.execution_time;
}

void calculateTimes(const vector<Job> &jobs, vector<int> &turnaround_times, vector<int> &waiting_times)
{
    int n = jobs.size();
    vector<Job> sorted_jobs = jobs;
    sort(sorted_jobs.begin(), sorted_jobs.end(), compareJobExecutionTime);

    int current_time = 0;

    for (int i = 0; i < n; ++i)
    {
        if (current_time < sorted_jobs[i].arrival_time)
        {
            current_time = sorted_jobs[i].arrival_time;
        }

        int waiting_time = current_time - sorted_jobs[i].arrival_time;
        waiting_times.push_back(waiting_time);

        int completion_time = current_time + sorted_jobs[i].execution_time;
        turnaround_times.push_back(completion_time - sorted_jobs[i].arrival_time);

        current_time = completion_time;
    }
}

void printOutput(const vector<int> &turnaround_times, const vector<int> &waiting_times)
{
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int n = turnaround_times.size();

    cout << "Job\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; ++i)
    {
        cout << (i + 1) << "\t" << turnaround_times[i] << "\t\t" << waiting_times[i] << "\n";
        total_turnaround_time += turnaround_times[i];
        total_waiting_time += waiting_times[i];
    }

    double avg_turnaround_time = static_cast<double>(total_turnaround_time) / n;
    double avg_waiting_time = static_cast<double>(total_waiting_time) / n;

    cout << "\nAverage Turnaround Time: " << avg_turnaround_time << "\n";
    cout << "Average Waiting Time: " << avg_waiting_time << "\n";
}

int main()
{
    int num_jobs;
    cout << "Enter the number of jobs: ";
    cin >> num_jobs;

    vector<Job> jobs(num_jobs);
    cout << "Enter arrival time and execution time for each job:\n";
    for (int i = 0; i < num_jobs; ++i)
    {
        cout << "Job " << (i + 1) << " - Arrival Time: ";
        cin >> jobs[i].arrival_time;
        cout << "Job " << (i + 1) << " - Execution Time: ";
        cin >> jobs[i].execution_time;
    }

    vector<int> turnaround_times;
    vector<int> waiting_times;
    calculateTimes(jobs, turnaround_times, waiting_times);

    cout << "\nShortest Job First (Non-preemptive) Scheduling Algorithm\n";
    printOutput(turnaround_times, waiting_times);

    return 0;
}