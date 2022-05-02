#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, pay, day, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pay >> day;
        v.push_back({day, pay});
    }
}

void Pro() {
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }
    while(pq.size()) {
        ans += pq.top(); pq.pop();
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}