#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid, at, bt, pr, rt, ct, wt, tat;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter AT, BT and Priority for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].rt = p[i].bt;
    }

    int time = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;

    while(completed < n) {
        int idx = -1, highPr = 1e9;
        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0 && p[i].pr < highPr) {
                highPr = p[i].pr;
                idx = i;
            }
        }

        if(idx != -1) {
            p[idx].rt--;
            time++;
            if(p[idx].rt == 0) {
                completed++;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                totalWT += p[idx].wt;
                totalTAT += p[idx].tat;
            }
        } else {
            time++;
        }
    }

    cout << "\nProcess AT BT PR CT WT TAT\n";
    for(auto pr : p) {
        cout << "P" << pr.pid << "\t"
             << pr.at << "\t"
             << pr.bt << "\t"
             << pr.pr << "\t"
             << pr.ct << "\t"
             << pr.wt << "\t"
             << pr.tat << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n;
    return 0;
}