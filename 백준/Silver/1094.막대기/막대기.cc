#include <bits/stdc++.h>
using namespace std;

int standard = 64;
int x, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x;
    while (x > 0) {
        if(standard > x) {
            standard /= 2;
        } else {
            ret++;
            x -= standard;
        }
    }
    cout << ret;
}