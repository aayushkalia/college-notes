#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid, at, bt, ct, wt, tat;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter AT and BT for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt;
    }

    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    int time = 0;
    float totalWT = 0, totalTAT = 0;

    cout << "\nGantt Chart:\n|";
    for(int i = 0; i < n; i++) {
        if(time < p[i].at)
            time = p[i].at;
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
        cout << " P" << p[i].pid << " |";
    }

    cout << "\n\nProcess AT BT CT WT TAT\n";
    for(auto pr : p) {
        cout << "P" << pr.pid << "\t"
             << pr.at << "\t"
             << pr.bt << "\t"
             << pr.ct << "\t"
             << pr.wt << "\t"
             << pr.tat << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n;
    return 0;
}