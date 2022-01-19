#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, string> _map1;
map<string, int> _map2;
int n, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		_map1[i] = s;
		_map2[s] = i;
	}

	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		if (atoi(s.c_str()) == 0) {
			cout << _map2[s] << "\n";
		}
		else {
			cout << _map1[atoi(s.c_str())] << "\n";
		}
	}
	return 0;
}
