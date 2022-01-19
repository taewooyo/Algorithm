#include <bits/stdc++.h>
using namespace std;

int n, m, words[51];
string s;

int count(int mask) {
    int cnt = 0;
    for (int word: words) {
        if(word && (word & mask) == word) cnt++;
    }
    return cnt;
}

int go(int index, int k, int mask) {
    if(k == 0) return count(mask);
    if(index == 26) return 0;
    int ret = 0;
    if(index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
        ret = max(ret, go(index+1, k-1, mask | (1 << index)));
        ret = max(ret, go(index+1, k, mask));
    }
    else ret = max(ret, go(index+1, k, mask));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char c : s) {
            words[i] |= (1 << (c - 'a'));       
        }
    }
    int mask = mask |= (1 << ('a' - 'a'));
    mask |= (1 << ('n' - 'a'));
    mask |= (1 << ('t' - 'a'));
    mask |= (1 << ('i' - 'a'));
    mask |= (1 << ('c' - 'a'));
    cout << go(0, m-5, mask);

}