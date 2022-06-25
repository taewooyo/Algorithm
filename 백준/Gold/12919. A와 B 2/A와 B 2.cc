#include <bits/stdc++.h>
using namespace std;

string S, T;
int ans = -1;
void Input() {
    cin >> S >> T;
}

void Go(string s, string t) {
    if (s == t) {
        ans = 1;
        return;
    }
    if(s.size() > t.size()) return;

    if(t[t.size() - 1] == 'A') {
        string temp = t;
        temp.erase(temp.size() - 1);
        Go(s, temp);
    }
    if(t[0] == 'B') {
        string temp = t;
        reverse(temp.begin(), temp.end());
        temp.erase(temp.size() - 1);
        Go(s, temp);
    }
}

void Pro() {
    Go(S, T);
    if(ans == -1) cout << 0;
    else cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}