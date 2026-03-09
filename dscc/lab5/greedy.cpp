#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nodes, T, n;
    cout<<"Enter nodes, maxTime, requests:\n";
    cin>>nodes>>T>>n;

    vector<int> used(T,0);

    for(int i=0;i<n;i++){
        int Ts,D,R,Tl;
        cout<<"Timestart Duration Required LatestTime:\n";
        cin>>Ts>>D>>R>>Tl;

        bool ok=false;
        for(int s=Ts;s<=Tl && !ok;s++){
            bool fit=true;
            for(int t=s;t<s+D;t++)
                if(t>=T || used[t]+R>nodes){fit=false;break;}

            if(fit){
                for(int t=s;t<s+D;t++) used[t]+=R;
                cout<<"Request "<<i+1<<" Accepted\n";
                ok=true;
            }
        }
        if(!ok) cout<<"Request "<<i+1<<" Rejected\n";
    }
    return 0;
}