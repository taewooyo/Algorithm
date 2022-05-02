#include <iostream>
#include <vector>

using namespace std;

string a, b, ans;
void Input() {
    cin >> a >> b;
}

void Pro() {
    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
        if(ans.size() >= b.size() && ans.substr(ans.size() - b.size(), b.size()) == b) {
            for(int j = 0; j < b.size(); j++) ans.pop_back();
        }
    }
    if(!ans.size()) cout << "FRULA" << "\n";
    else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}