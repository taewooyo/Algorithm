#include <bits/stdc++.h>
using namespace std;

int n, _end;
int a[1023];
vector<int> ret[14];
void go(int s, int e, int level) {
    if(s > e) return;
    if(s == e) {
        ret[level].push_back(a[s]);
        return;
    }
    int mid = (s + e) / 2;
    ret[level].push_back(a[mid]);
    go(s, mid-1, level+1);
    go(mid+1, e, level+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    _end = pow(2, n) - 1;
    for (int i = 0; i < _end; i++) cin >> a[i];
    go(0, _end, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}