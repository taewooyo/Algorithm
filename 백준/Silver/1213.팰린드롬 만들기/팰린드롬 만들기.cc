#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string str, ret;
char mid;
int cnt[200], flag;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	for (int i = 0; i < str.size(); i++) cnt[str[i]]++;
	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i]) {
			if (cnt[i] & 1) { // 홀수
				mid = char(i);
				flag++;
				cnt[i]--;
			}
			if (flag == 2) break;
			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}
	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2) cout << "I'm Sorry Hansoo\n";
	else cout << ret << '\n';

	return 0;
}
