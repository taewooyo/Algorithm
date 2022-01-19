#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s, pre, suf, partten;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	cin >> partten;

	int deli = partten.find('*');
	pre = partten.substr(0, deli);
	suf = partten.substr(deli + 1);

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (pre.size() + suf.size() > s.size())
			cout << "NE\n";
		else {
			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) {
				cout << "DA\n";
			}
			else cout << "NE\n";
		}
	}
	return 0;
}
