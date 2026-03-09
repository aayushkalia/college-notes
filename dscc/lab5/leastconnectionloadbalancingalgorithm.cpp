#include <iostream>
#include <vector>
using namespace std;

int main() {
    int servers, requests;
    cout << "Enter number of servers: ";
    cin >> servers;
    cout << "Enter number of requests: ";
    cin >> requests;

    vector<int> load(servers, 0);

    for(int i = 0; i < requests; i++) {
        int idx = 0;
        for(int j = 1; j < servers; j++) {
            if(load[j] < load[idx])
                idx = j;
        }
        load[idx]++;
        cout << "Request " << i+1 << " assigned to Server " << idx+1 << endl;
    }

    cout << "\nFinal Server Load:\n";
    for(int i = 0; i < servers; i++) {
        cout << "Server " << i+1 << ": " << load[i] << " connections\n";
    }
    return 0;
}