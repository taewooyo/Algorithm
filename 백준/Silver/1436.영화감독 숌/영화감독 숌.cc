#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int i = 666;
    while(true) {
        s = to_string(i++);
        if(s.find("666") != string::npos) {
            n--;
        }
        if(n==0) break;
    }

    cout << s;
    return 0;
}