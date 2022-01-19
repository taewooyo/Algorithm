#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> n;
		map<string, int> _map;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			_map[b]++;
		}
		ll ret = 1;
		for (auto it : _map) {
			ret *= ((ll)it.second + 1);
		}
		cout << ret - 1 << '\n';
	}

	return 0;
}
