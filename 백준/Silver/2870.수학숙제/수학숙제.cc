#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, l, r;
string s;
vector<string> v;
string update(string str) {
    if (str.size()) {
        while (true) {
            if (str.size() && str.front() == '0')
                str.erase(str.begin());
            else break;
        }

        if (str.size() == 0) str = "0";
    }
    return str;
}

bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;
    while (m--) {
        cin >> s;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') temp += s[i];
            else {
                string str = update(temp);
                if (str.size()) v.push_back(str);
                temp = "";
            }

        }
        string str = update(temp);
        if (str.size()) v.push_back(str);
        temp = "";
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) cout << it << '\n';
    return 0;
}