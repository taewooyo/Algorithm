#include <bits/stdc++.h>
using namespace std;

int a[100004];
int dy[] = {1, 1, 2};
int dx[] = {1, -1, 0};
int n, k, ret;
queue<int> q;
int visited[100004];
int _prev[100004];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    q.push(n);
    visited[n] = 1;

    while(q.size()) {
        int here = q.front();
        q.pop();

        if(here == k) {
            ret = visited[k];
            break;
        }
        for (int i = 0; i < 3; i++) {
            int next = here * dy[i] + dx[i];
            if(next < 0 || next > 100000 || visited[next]) continue;
            visited[next] = visited[here] + 1;
            _prev[next] = here;
            q.push(next);
        }
    }
    cout << ret - 1 << '\n';
    vector<int> v;
    int idx = k;
    while(idx != n) {
        v.push_back(idx);
        idx = _prev[idx];
    }
    v.push_back(n);

    reverse(v.begin(), v.end());
    for (auto it: v) cout << it << ' ';
}