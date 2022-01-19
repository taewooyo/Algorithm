#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--){
        cin >> s;
        stack<char> stk;
        bool flag = true;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '(') {
                stk.push(s[i]);
            }
            else { // case : )
                if(stk.size()) stk.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(!flag || stk.size()) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    return 0;
}