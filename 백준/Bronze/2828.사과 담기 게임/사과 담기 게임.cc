#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, j, l, r;
int apple;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> j;
    l = 1;
    int ret = 0;
    for (int i = 0; i < j; i++) {
        r = l + m - 1;
        cin >> apple;
        if (apple >= l && apple <= r) continue;
        else {
            if (apple < l) {
                ret += (l - apple);
                l = apple;
            }
            else {
                ret += (apple - r);
                l += (apple - r);
            }
        }
    }
    cout << ret;

    return 0;
}