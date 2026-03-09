#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void printLoad(const vector<int>& load) {
    for (int i = 0; i < load.size(); i++)
        cout << "Server " << i + 1 << " Load = " << load[i] << endl;
    cout << endl;
}


void roundRobin(int servers, int requests, vector<int>& load) {
    load.assign(servers, 0);
    for (int i = 0; i < requests; i++)
        load[i % servers]++;
}


void weightedRoundRobin(int servers, int requests, vector<int>& load) {
    vector<int> weights(servers);
    cout << "Enter server weights:\n";
    for (int i = 0; i < servers; i++)
        cin >> weights[i];

    load.assign(servers, 0);

    int i = 0;
    for (int r = 0; r < requests; ) {
        if (weights[i] > 0) {
            load[i]++;
            weights[i]--;
            r++;
        }
        i = (i + 1) % servers;
    }
}

void leastLoaded(int servers, int requests, vector<int>& load) {
    load.assign(servers, 0);
    for (int i = 0; i < requests; i++) {
        int minIdx = 0;
        for (int j = 1; j < servers; j++)
            if (load[j] < load[minIdx])
                minIdx = j;
        load[minIdx]++;
    }
}


void randomAllocation(int servers, int requests, vector<int>& load) {
    load.assign(servers, 0);
    for (int i = 0; i < requests; i++)
        load[rand() % servers]++;
}


void serverFailure(int servers, vector<int>& load) {
    int failed;
    cout << "Enter server number to fail: ";
    cin >> failed;
    failed--;

    int failedLoad = load[failed];
    load[failed] = 0;

    for (int i = 0; i < failedLoad; i++) {
        int minIdx = (failed == 0) ? 1 : 0;
        for (int j = 0; j < servers; j++)
            if (j != failed && load[j] < load[minIdx])
                minIdx = j;
        load[minIdx]++;
    }
}

int main() {
    int servers, requests;
    cout << "Enter number of servers: ";
    cin >> servers;
    cout << "Enter number of requests: ";
    cin >> requests;

    vector<int> load;

    roundRobin(servers, requests, load);
    cout << "\nRound Robin:\n";
    printLoad(load);

    weightedRoundRobin(servers, requests, load);
    cout << "Weighted Round Robin:\n";
    printLoad(load);

    leastLoaded(servers, requests, load);
    cout << "Least Loaded:\n";
    printLoad(load);

    randomAllocation(servers, requests, load);
    cout << "Random Allocation:\n";
    printLoad(load);

    serverFailure(servers, load);
    cout << "After Server Failure:\n";
    printLoad(load);

    return 0;
}