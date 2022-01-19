#include <bits/stdc++.h>
using namespace std;

int n, m, a[54][54], ret = 987654321;
vector<pair<int, int>> chicken, home;
vector<pair<int, int>> candid;

int getDistance() {
    int result = 0;
    for (int i = 0; i < home.size(); i++) {
        int _min = 987654321;
        for (int j = 0; j < candid.size(); j++) {
            int dist = abs(home[i].first - candid[j].first) + abs(home[i].second - candid[j].second);
            _min = min(dist, _min);
        }
        result += _min;
    }
    return result;
}

void go(int here, int cnt) {
    if (cnt == m) {
        ret = min(ret, getDistance());
        return;
    }

    for (int i = here + 1; i < chicken.size(); i++) {
        candid.push_back({ chicken[i].first, chicken[i].second });
        go(i, cnt + 1);
        candid.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) home.push_back({ i, j });
            else if (a[i][j] == 2) chicken.push_back({ i, j });
        }
    }

    go(-1, 0);
    cout << ret << '\n';
    return 0;
}
