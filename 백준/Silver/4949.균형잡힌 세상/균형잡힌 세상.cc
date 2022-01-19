#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {

        if(s[i] == '.') break;
        else if(s[i] == '(' || s[i] == '[') stk.push(s[i]);
        else if(s[i] == ')') { 
            if(!stk.size() || stk.top() == '[') return false;
            else if(stk.top() == '(') stk.pop();
        }
        else if(s[i] == ']') { 
            if(!stk.size() || stk.top() == '(') return false;
            else if(stk.top() == '[') stk.pop();
        }

    }
    return (!stk.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        getline(cin, s);
        if(s == ".") break;
        if(check(s)) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}