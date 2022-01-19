#include <bits/stdc++.h>
using namespace std;

string s;
int alpha[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'a']++;
	}

	for (auto& it : alpha) cout << it << ' ';

	return 0;
}
