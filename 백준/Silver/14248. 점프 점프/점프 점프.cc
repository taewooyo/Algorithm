#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> v;
bool visited[100004];
void Input() {
    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    cin >> s;
}

void Dfs(int here) {
    if(here < 1 || here > n) return;
    visited[here] = true;
    Dfs(here + v[here]);
    Dfs(here - v[here]);
}

void Pro() {
    int ans = 0;
    Dfs(s);
    for (int i = 1; i <= n; i++) {
        if(visited[i]) ans++;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}