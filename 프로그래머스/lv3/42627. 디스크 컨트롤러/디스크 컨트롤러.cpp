#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0, _time = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    while(idx < jobs.size() || !pq.empty()) {
        if(idx < jobs.size() && _time >= jobs[idx][0]) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
            continue;
        }
        
        if(!pq.empty()) {
            _time += pq.top().first; // 완료된 시간
            answer += _time - pq.top().second; // 기다린 시간
            pq.pop();
        }
        else {
            _time = jobs[idx][0];
        }
    }
    
    return answer / jobs.size();
}