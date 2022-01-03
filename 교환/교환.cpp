#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;
int K;
string str, ans = "0";
queue<string> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> K;
    q.push(s);

    for(int i = 0; i < K; i++) {
        set<string> st;
        int size = q.size();

        for(int l = 0; l < size; l++) {
            s = q.front(); q.pop();

            if(st.count(s) == 1) continue;
            st.insert(s);

            for(int j = 0; j < s.size() - 1; j++) {
                for(int k = j+1; k < s.size(); k++) {
                    if(j == 0 && s[k] == '0') continue;
                    swap(s[j], s[k]);
                    q.push(s);
                    swap(s[j], s[k]);
                }
            }
        }
    }

    while(q.size()) {
        ans = max(ans, q.front());
        q.pop();
    }

    if(ans[0] == '0') cout << -1 << '\n';
    else cout << ans.c_str() << '\n';
}