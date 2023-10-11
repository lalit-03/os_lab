#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,pair<int,string>>> processes = {{2,{6,"P1"}}, {5,{2,"P2"}}, {1,{8,"P3"}}, {0,{3,"P4"}}, {4,{4,"P5"}}};
    int num_process = processes.size();
    sort(processes.begin(),processes.end());
    reverse(processes.begin(),processes.end());
    priority_queue<pair<int,pair<int,string>>> q;
    map<string,int> orig_arrival{};
    for(auto p:processes) orig_arrival[p.second.second] = p.first;
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
        if(processes.size() && t - p.first > processes.back().first){
            waiting += t - p.second.first;

            int t1 = processes.back().first - t;
            p.first += t1;
            cout<<"Running "<<p.second.second<<" for "<<t1<<" ms\n";
            t += t1;
            p.second.first = t;
            cout<<"t is now: "<<t<<'\n';
            q.push(p);
        }else{
            waiting += t - p.second.first;

            t += -p.first;
            cout<<"Running "<<p.second.second<<" for "<<-p.first<<" ms\n";
            turnaround += t - orig_arrival[p.second.second];
            cout<<p.second.second<<" Turnaround time: "<<t-orig_arrival[p.second.second]<<'\n';
            cout<<"Process "<<p.second.second<<" has ended.\n";
            cout<<"t is now: "<<t<<'\n';
            
        }
    }
    cout<<"Average waiting time: "<<(double)waiting/num_process<<"\nAverage turnaround time: "<<(double)turnaround/num_process<<"\n";
    return 0;
}