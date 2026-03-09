#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid, bt, rt, ct, tat, wt;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    vector<Process> p(n);
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Burst Time for P" << i+1 << ": ";
        cin >> p[i].bt;
        p[i].rt = p[i].bt;
    }

    int time = 0, completed = 0;
    while(completed < n) {
        for(int i = 0; i < n; i++) {
            if(p[i].rt > 0) {
                if(p[i].rt > tq) {
                    time += tq;
                    p[i].rt -= tq;
                } else {
                    time += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = time;
                    completed++;
                }
            }
        }
    }

    float totalWT = 0, totalTAT = 0;
    cout << "\nProcess BT CT WT TAT\n";
    for(int i = 0; i < n; i++) {
        p[i].tat = p[i].ct;
        p[i].wt = p[i].tat - p[i].bt;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
        cout << "P" << p[i].pid << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].wt << "\t"
             << p[i].tat << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n;
    return 0;
}