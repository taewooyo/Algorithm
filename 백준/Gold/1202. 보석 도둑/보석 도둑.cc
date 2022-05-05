#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

int n, k;
vector<pair<ll, ll>> v;
vector<ll> bag;

void Input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll w, c; cin >> w >> c;
        v.push_back({w, c});
    }
    for (int i = 0; i < k; i++) {
        ll a; cin >> a;
        bag.push_back(a);
    }
}

void Pro() {
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    priority_queue<ll> pq;
    ll ans = 0;

    for (int j = 0, i = 0; i < k; i++) {
        while(j < n && v[j].first <= bag[i])
            pq.push(v[j++].second);
        if(pq.size()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}