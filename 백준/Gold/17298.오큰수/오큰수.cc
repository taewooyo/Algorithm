#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
int n, a[1000004], ret[1000004];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fill(ret, ret + 1000004, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (stk.size() && a[stk.top()] < a[i]) {
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 0; i < n; i++) cout << ret[i] << ' ';
}
