#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char a[65][65];
string s;

string quard(int y, int x, int size) {
    if (size == 1) {
        string str;
        str = a[y][x];
        return str;
    }
    string ret = "";
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (a[y][x] != a[i][j]) {
                ret += "(";
                ret += quard(y, x, size / 2);
                ret += quard(y, x + size / 2, size / 2);
                ret += quard(y + size / 2, x, size / 2);
                ret += quard(y + size / 2, x + size / 2, size / 2);
                ret += ")";
                return ret;
            }
        }
    }
    string str;
    str = a[y][x];
    return str;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }
    string ret = quard(0, 0, n);
    cout << ret << '\n';
    return 0;
}