#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
struct Data {
    int d, p;
    Data(int d, int p): d(d), p(p) {}
    bool operator< (const Data& o) const {
        if(p == o.p) return d > o.d;
        return p < o.p;
    }
};
priority_queue<Data> pq;
int ans;
int visited[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int d, p; cin >> p >> d;
        pq.push(Data(d, p));
    }

    while(pq.size()) {
        Data data = pq.top(); pq.pop();
        for(int i = data.d; i >= 1; i--) {
            if(!visited[i]) {
                ans += data.p;
                visited[i] = true;
                break;
            }
        }
    }
    cout << ans;
}