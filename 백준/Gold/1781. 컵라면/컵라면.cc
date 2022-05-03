#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;
vector<pair<int, int>> v;
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int deadline, cup;
        cin >> deadline >> cup;
        v.push_back({deadline, cup});
    }
}

void Pro() {
    int ret = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        ret += v[i].second;
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            ret -= pq.top();
            pq.pop();
        }
    }
    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}