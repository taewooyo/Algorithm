#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tree[1 << 21];
int n, m, k;
int base;

void update(int idx, ll value) {
    idx += (base - 1);
    tree[idx] = value;
    while(idx >>= 1) {
        tree[idx] = (tree[idx << 1] + tree[(idx << 1) | 1]);
    }
}

ll getSum(int l, int r) {
    l += (base-1);
    r += (base-1);
    ll sum = 0;
    while(l<=r) {
        if((l & 1) == 1) sum += tree[l];
        if((r & 1) == 0) sum += tree[r];

        l = (l+1) >> 1;
        r = (r-1) >> 1;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    base = 1;
    while(base < n) base <<= 1;
    for(int i = base; i < n+base; i++) cin >> tree[i];

    for(int i = base-1; i > 0; i--) {
        tree[i] = tree[i<<1] + tree[(i<<1) | 1];
    }

    for(int i = 0; i < m+k; i++) {
        int a, b; long long c;
        cin >> a >> b >> c;
        if(a == 1) update(b, c);
        else cout << getSum(b, c) << '\n';
    }

}