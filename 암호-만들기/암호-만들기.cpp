#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> v, temp;
char arr[] = {'a', 'e', 'i', 'o', 'u'};
void Input() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char x;
        cin >> x;
        v.push_back(x);
    }
}

bool IsOk() {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
            cnt1++;
        }
        else cnt2++;
    }
    return (cnt1 >= 1 && cnt2 >= 2);
}

void Go(int level, int idx) {
    if(level == l) {
        if (IsOk()) {
            for (auto& it: temp) cout << it;
            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        temp.push_back(v[i]);
        Go(level+1, i+1);
        temp.pop_back();
    }
}

void Pro() {
    sort(v.begin(), v.end());
    Go(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    Pro();

    return 0;
}