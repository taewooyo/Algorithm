#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int parking[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j < e; j++) {
			parking[j]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		if (parking[i] == 1) ans += a;
		else if (parking[i] == 2) ans += (b * 2);
		else if (parking[i] == 3) ans += (c * 3);
	}

	cout << ans;
	return 0;
}
