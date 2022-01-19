#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;
int cnt[26];
string v = "aeiou";
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cin >> str;
        if (str == "end") break;
        int vowel_cnt = 0, consonant_cnt = 0;
        fill(cnt, cnt + 26, 0);
        bool flag = 0;
        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            cnt[idx]++;
            if (isVowel(str[i])) {
                vowel_cnt++;
                consonant_cnt = 0;
            }
            else {
                vowel_cnt = 0;
                consonant_cnt++;
            }
            // case 2
            if (vowel_cnt == 3 || consonant_cnt == 3) {
                flag = 1;
                break;
            }
            // case 3
            if (i >= 1 && str[i - 1] == str[i] && (str[i] != 'e' && str[i] != 'o')) {
                flag = 1;
                break;
            }
        }

        bool flag2 = 0;
        for (int i = 0; i < v.size(); i++) {
            int idx = v[i] - 'a';
            if (cnt[idx]) {
                flag2 = 1;
                break;
            }
        }
        if (!flag2) flag = 1;

        if (flag) cout << "<" << str << ">" << " is not acceptable.\n";
        else cout << "<" << str << ">" << " is acceptable.\n";
    }

    return 0;
}