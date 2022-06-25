#include <bits/stdc++.h>
using namespace std;

int n, a[104], oper[4];
int ret1 = 2e9;
int ret2 = -2e9;
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 4; i++) cin >> oper[i];
}

void Go(int idx, int plus, int minus, int multi, int div, int sum) {
    if(idx == n - 1) {
        ret1 = min(ret1, sum);
        ret2 = max(ret2, sum);
        return;
    }
    if(plus > 0) Go(idx + 1, plus - 1, minus, multi, div, sum + a[idx + 1]);
    if(minus > 0) Go(idx + 1, plus, minus - 1, multi, div, sum - a[idx + 1]);
    if(multi > 0) Go(idx + 1, plus, minus, multi - 1, div, sum * a[idx + 1]);
    if(div > 0) Go(idx + 1, plus, minus, multi,  div - 1, sum / a[idx + 1]);
}

void Pro() {
    Go(0, oper[0], oper[1], oper[2], oper[3], a[0]);
    cout << ret2 << '\n' << ret1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Pro();
}