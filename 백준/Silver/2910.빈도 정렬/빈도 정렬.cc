#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, int> mp;
map<int, int> imp;
vector<pair<int, int>> v;
int n, c, a[1004];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return imp[a.second] < imp[b.second];
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if (imp[a[i]] == 0) imp[a[i]] = i + 1;
    }

    for (auto it : mp) {
        v.push_back({ it.second, it.first });
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) {
        for (int i = 0; i < it.first; i++) {
            cout << it.second << ' ';
        }
    }
    return 0;
}