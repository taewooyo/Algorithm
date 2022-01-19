#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100004];
int tree[400000];
int base;

int getSum(int l, int r) {
    l += (base - 1);
    r += (base - 1);
    int sum = 0;
    while(true) {
        if(l > r) break;
        if(l % 2 == 1) sum += tree[l];
        if(r % 2 == 0) sum += tree[r];

        l = (l+1) / 2;
        r = (r-1) / 2;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    
    base = 1;
    while(base < n) base *= 2;
    for(int i = base; i < n+base; i++) cin >> tree[i];

    for(int i = base - 1; i > 0; i--) {
        tree[i] = tree[i<<1] + tree[(i<<1)|1];
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << getSum(a, b) << '\n';
    }
    return 0;
}