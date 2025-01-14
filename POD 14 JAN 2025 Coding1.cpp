/*
Single File Programming Question
Problem Statement:



John is working on a project where he needs to schedule several jobs to maximize profit while meeting their respective deadlines. Each job is represented by a unique job number, has a specific deadline by which it must be completed, and is associated with a certain profit upon completion. 



John wants to sequence these jobs efficiently to ensure that the total profit is maximized while adhering to the deadlines.

Input format :
The first line of input contains an integer N, representing the number of jobs.

Each of the next N lines contains three space-separated integers: jobNum, deadline, and profit, where jobNum is the job number, the deadline is the deadline by which the job must be completed, and profit is the profit associated with completing the job.

Output format :
The output prints the sentence "Job sequenced in order:" followed by a space-separated list of job numbers in the order they should be scheduled to maximize the total profit.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N ≤ 1000

1 ≤ Deadline , Profit ≤ 1000

The deadlines are distinct positive integers.

Sample test cases :
Input 1 :
5
1 2 20
2 2 15
3 1 10
4 3 5
5 3 1
Output 1 :
Job sequenced in order: 2 1 4 
Input 2 :
4
1 1 20
2 2 30
3 3 10
4 1 5
Output 2 :
Job sequenced in order: 1 2 3 
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/#include <bits/stdc++.h>
using namespace std;

// Structure to represent a job
struct Job {
    int jobNum, deadline, profit;
};

// Comparison function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    // Input jobs
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].jobNum >> jobs[i].deadline >> jobs[i].profit;
    }

    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (const auto &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Create a schedule array to track which jobs are scheduled
    vector<int> schedule(maxDeadline + 1, -1); // -1 means no job scheduled

    vector<int> result; // To store the order of jobs scheduled
    for (const auto &job : jobs) {
        // Try to schedule the job at the latest available time before its deadline
        for (int time = job.deadline; time > 0; time--) {
            if (schedule[time] == -1) {
                schedule[time] = job.jobNum;
                result.push_back(job.jobNum);
                break;
            }
        }
    }

    // Output the result
    cout << "Job sequenced in order:";
    for (int jobNum : result) {
        cout << " " << jobNum;
    }
    cout << endl;

    return 0;
}
