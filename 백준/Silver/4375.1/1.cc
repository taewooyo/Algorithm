#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    while(cin >> n) {
        int val = 1, ret = 1;
        while(true) {
            if(val % n == 0) {
                cout << ret << '\n';
                break;
            }
            else {
                val = val * 10 + 1;
                val %= n;
                ret++;
            }
        }
    }
}