#include <bits/stdc++.h>
using namespace std;

int getDiff(int a, int b) {
    if(b >= a) return b - a;
    return 26 - (a - b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        string s[4];
        cin >> s[0];
        if(s[0] == "#") break;
        cin >> s[1] >> s[2];

        vector<int> v;
        for (int i = 0; i < s[0].size(); i++) {
            int len = getDiff(s[0][i], s[1][i]);
            v.push_back(len);
        }

        for (int i = 0; i < s[2].size(); i++) {
            if(s[2][i] + v[i] >= 'z') s[3] += char(((s[2][i] - 'a' + v[i]) % 26) + 'a');
            else s[3] += char(s[2][i] + v[i]);
        }
        
        cout << s[0] << ' ' << s[1] << ' ' << s[2] << ' ' << s[3] << '\n';
    }
    return 0;
}