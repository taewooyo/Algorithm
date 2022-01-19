#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, cnt;
int a[15004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	int lo = 0, hi = n - 1;
	while (lo < hi) {
		if (a[lo] + a[hi] == m) cnt++, lo++;
		else if (a[lo] + a[hi] < m) lo++;
		else hi--;
	}
	cout << cnt << "\n";
	

	return 0;
}
