#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;

int n, l, r, ans;
pair<int ,int> L[1000004];
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> L[i].first >> L[i].second;
    }
}

void Pro() {
    sort(L, L + n);
    l = L[0].first; r = L[0].second;
    for (int i = 1; i < n; i++) {
        if(r < L[i].first) {
            ans += (r - l);
            l = L[i].first;
            r = L[i].second;
        }
        else if(L[i].first <= r && L[i].second >= r) r = L[i].second;
    }
    ans += (r - l);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}