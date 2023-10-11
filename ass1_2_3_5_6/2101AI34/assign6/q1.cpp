#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,pair<int,string>>> processes = {{0,{5,"P1"}}, {1,{3,"P2"}}, {2,{8,"P3"}}, {3,{6,"P4"}}};
    sort(processes.begin(),processes.end());
    int t = 0;
    int waiting = 0, turnaround = 0;
    for(auto p: processes){
        cout<<p.second.second<<" Waiting: "<<t - p.first<<" Turnaround: "<<t + p.second.first - p.first<<'\n';
        waiting += t - p.first;
        turnaround += t + p.second.first - p.first;
        t += p.second.first;
        cout<<"t is now: "<<t<<'\n';
    }
    cout<<"Average waiting time: "<<(double)waiting/processes.size()<<"\nAverage turnaround time: "<<(double)turnaround/processes.size()<<"\n";
    return 0;
}