#include <iostream>

using namespace std;
typedef long long ll;

ll dp[5004];

ll go(int n) {
    if (n <= 1) return n;
    if (dp[n]) return dp[n];
    return dp[n] = go(n - 2) + go(n - 3);
}

int main() {
    dp[1] = dp[2] = 1;
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << go(n) << '\n';
    }

}