#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> v;
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        v.push_back({e, s});
    }
}

void Pro() {
    sort(v.begin(), v.end());
    int from = v[0].second;
    int to = v[0].first;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].second < to) continue;
        from = v[i].second;
        to = v[i].first;
        ans++;
    }
    cout << ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}