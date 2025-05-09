// #include <iostream>
// #include <vector>
// using namespace std;

// struct Job {
//     int id;
//     int deadline;
//     int profit;
// };

// bool sortByProfit(const Job& job1, const Job& job2) {
//     return job1.profit > job2.profit;
// }

// int scheduleJobs(vector<Job>& jobs) {
//     sort(jobs.begin(), jobs.end(), sortByProfit);

//     int maxDeadline = 0;
//     for (const Job& job : jobs) {
//         maxDeadline = std::max(maxDeadline, job.deadline);
//     }

//     vector<int> slots(maxDeadline, -1);
//     vector<Job> scheduledJobs;
//     int totalProfit = 0;

//     for (const Job& job : jobs) {
//         for (int slot = job.deadline - 1; slot >= 0; --slot) {
//             if (slots[slot] == -1) {
//                 slots[slot] = job.id;
//                 scheduledJobs.push_back(job);
//                 totalProfit += job.profit;
//                 break;
//             }
//         }
//     }

//     cout << "Scheduled jobs: ";
//     for (const Job& job : scheduledJobs) {
//         cout << job.id << " ";
//     }
//     cout <<endl;

//     return totalProfit;
// }

// int main() {
// 	int n;
//     cout << "Enter the number of jobs you want to enter: ";
//     cin >> n;
//     vector<Job> jobs(n);
//     cout << "Enter the details of the jobs:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Job " << (i + 1) << ":\n";
//         cout << "Enter the id of the job: ";
//         cin >> jobs[i].id;
//         cout << "Enter the deadline of the job: ";
//         cin >> jobs[i].deadline;
//         cout << "Enter the profit of the job: ";
//         cin >> jobs[i].profit;
//     }
	
//     int totalProfit = scheduleJobs(jobs);
//     cout << "Total profit: " << totalProfit << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

// Manual selection sort to sort jobs by profit in descending order
void sortByProfit(vector<Job>& jobs) {
    int n = jobs.size();
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (jobs[j].profit > jobs[max_idx].profit) {
                max_idx = j;
            }
        }
        swap(jobs[i], jobs[max_idx]);
    }
}

int scheduleJobs(vector<Job>& jobs) {
    sortByProfit(jobs);  // Use manual sort

    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> slots(maxDeadline, -1);
    vector<Job> scheduledJobs;
    int totalProfit = 0;

    for (const Job& job : jobs) {
        for (int slot = job.deadline - 1; slot >= 0; --slot) {
            if (slots[slot] == -1) {
                slots[slot] = job.id;
                scheduledJobs.push_back(job);
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Scheduled jobs: ";
    for (const Job& job : scheduledJobs) {
        cout << job.id << " ";
    }
    cout << endl;

    return totalProfit;
}

int main() {
    int n;
    cout << "Enter the number of jobs you want to enter: ";
    cin >> n;
    vector<Job> jobs(n);
    cout << "Enter the details of the jobs:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << (i + 1) << ":\n";
        cout << "Enter the id of the job: ";
        cin >> jobs[i].id;
        cout << "Enter the deadline of the job: ";
        cin >> jobs[i].deadline;
        cout << "Enter the profit of the job: ";
        cin >> jobs[i].profit;
    }

    int totalProfit = scheduleJobs(jobs);
    cout << "Total profit: " << totalProfit << endl;

    return 0;
}
