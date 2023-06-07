#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int arrival_time;
    int execution_time;
    int priority;
};

void calculateTimes(const vector<Job> &jobs, vector<int> &turnaround_times, vector<int> &waiting_times)
{
    int n = jobs.size();

    vector<bool> completed(n, false);
    vector<int> remaining_times(n, 0);

    for (int i = 0; i < n; ++i)
    {
        remaining_times[i] = jobs[i].execution_time;
    }

    int current_time = 0;
    int completed_jobs = 0;

    while (completed_jobs < n)
    {
        int min_priority_job = -1;
        int min_priority = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (jobs[i].arrival_time <= current_time && !completed[i] && jobs[i].priority < min_priority)
            {
                min_priority = jobs[i].priority;
                min_priority_job = i;
            }
        }

        if (min_priority_job == -1)
        {
            current_time++;
            continue;
        }

        int job_index = min_priority_job;
        completed[job_index] = true;
        completed_jobs++;
        current_time += jobs[job_index].execution_time;

        turnaround_times[job_index] = current_time - jobs[job_index].arrival_time;
        waiting_times[job_index] = turnaround_times[job_index] - jobs[job_index].execution_time;
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
    cout << "Enter arrival time, execution time, and priority for each job:\n";
    for (int i = 0; i < num_jobs; ++i)
    {
        cout << "Job " << (i + 1) << " - Arrival Time: ";
        cin >> jobs[i].arrival_time;
        cout << "Job " << (i + 1) << " - Execution Time: ";
        cin >> jobs[i].execution_time;
        cout << "Job " << (i + 1) << " - Priority: ";
        cin >> jobs[i].priority;
    }

    vector<int> turnaround_times(num_jobs, 0);
    vector<int> waiting_times(num_jobs, 0);

    calculateTimes(jobs, turnaround_times, waiting_times);

    cout << "\nPriority Scheduling Algorithm (Non-preemptive)\n";
    printOutput(turnaround_times, waiting_times);

    return 0;
}