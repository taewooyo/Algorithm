#include <bits/stdc++.h>
using namespace std;

int n, k, ret, _ret;
int dist[100004];
int cnt[100004];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n' << 1;
        return 0;
    }

    dist[n] = 0; // 가는 최단 시간
    cnt[n] = 1; // 가는 방법가지수 저장
    q.push(n);

    while (q.size()) {
        int here = q.front(); q.pop();

        for (int next : {here - 1, here + 1, here * 2}) {
            if (0 <= next && next <= 100000) {
                if (!dist[next]) {
                    q.push(next);
                    dist[next] = dist[here] + 1;
                    cnt[next] += cnt[here];
                }
                else if (dist[next] == dist[here] + 1) {
                    cnt[next] += cnt[here];
                }
            }
        }
    }
    cout << dist[k] << '\n';
    cout << cnt[k] << '\n';
    return 0;
}
