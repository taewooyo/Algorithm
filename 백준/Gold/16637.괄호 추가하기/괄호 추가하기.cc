#include <bits/stdc++.h>
using namespace std;

int n, ret = INT_MIN;
string s;
vector<int> num;
vector<char> oper;

int calc(char o, int a, int b) {
    if(o == '+') return a + b;
    else if(o == '-') return a - b;
    return a * b;
}

void go(int here, int sum) {
    if(here == num.size() - 1) {
        ret = max(ret, sum);
        return;
    }

    go(here+1, calc(oper[here], sum, num[here+1]));
    if(here+1 < num.size() - 1) {
        int temp = calc(oper[here+1], num[here+1] , num[here+2]);
        go(here+2, calc(oper[here], sum, temp));
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        if(i%2 == 0) num.push_back(s[i]-'0');
        else oper.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret;
    return 0;
}