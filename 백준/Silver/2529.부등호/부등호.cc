#include <bits/stdc++.h>
using namespace std;

int n, _max, _min;
int num[10];
char s[20];
vector<string> ret;

bool isOk(char a, char b, char c) {
    if(a < b && c == '<') return true;
    if(a > b && c == '>') return true;
    return false;
}

void go(int idx, string str) {
    if(idx == n+1) {
        ret.push_back(str);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if(num[i]) continue;
        if(idx == 0 || isOk(str[idx-1], i + '0', s[idx-1])) {
            num[i] = 1;
            go(idx + 1, str + to_string(i));
            num[i] = 0;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << '\n' << ret[0] << '\n';
    return 0;
}