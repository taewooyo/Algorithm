#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t, temp, ret = -2e9;
int a[100004], psum[100004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + a[i - 1];
	}

	for (int i = t; i <= n; i++) {
		ret = max(ret, psum[i] - psum[i - t]);
	}
	cout << ret;
	return 0;
}
