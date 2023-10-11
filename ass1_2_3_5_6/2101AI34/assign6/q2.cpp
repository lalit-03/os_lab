#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,pair<int,string>>> processes = {{2,{6,"P1"}}, {5,{2,"P2"}}, {1,{8,"P3"}}, {0,{3,"P4"}}, {4,{4,"P5"}}};
    int num_process = processes.size();
    sort(processes.begin(),processes.end());
    reverse(processes.begin(),processes.end());
    priority_queue<pair<int,pair<int,string>>> q;
    int t = 0;
    int waiting = 0, turnaround = 0;
    while(q.size() || processes.size()){
        while(processes.size() && processes.back().first <= t){
            auto p = processes.back();
            processes.pop_back();
            q.push({-p.second.first,{p.first,p.second.second}});
        }
        if(q.size() == 0){
            auto p = processes.back();
            processes.pop_back();
            t = p.first;
            q.push({-p.second.first,{p.first,p.second.second}});
        }
        auto p = q.top();
        q.pop();
        cout<<p.second.second<<" Waiting: "<<t - p.second.first<<" Turnaround: "<< t - p.second.first - p.first<<"\n";
        waiting += t - p.second.first;
        t += -p.first;
        turnaround += t - p.second.first;
        cout<<"t is now: "<<t<<'\n';
    }
    cout<<"Average waiting time: "<<(double)waiting/num_process<<"\nAverage turnaround time: "<<(double)turnaround/num_process<<"\n";
    return 0;
}