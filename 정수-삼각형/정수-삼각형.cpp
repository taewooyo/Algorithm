#include<bits/stdc++.h>
using namespace std;

int arr[501][501];
int dp[501][501];
int N;

int get_dp(int x, int y) {
    if(x == 1) return arr[1][1];
    if(dp[x][y] != -1) return dp[x][y];
    if(y == 1) dp[x][y] = get_dp(x - 1, y) + arr[x][y];
    else {
        dp[x][y] = max(get_dp(x - 1, y), get_dp(x - 1, y - 1)) + arr[x][y];
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    int result;
    int answer = 0;
    for(int i = 1; i <= N; i++) {
        result = get_dp(N, i);
        answer = max(result, answer);
    }
    cout << answer << '\n';
}