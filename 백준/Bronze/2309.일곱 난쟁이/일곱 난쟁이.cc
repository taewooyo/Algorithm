#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
typedef long long int ll;

vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += v[i];
		}
		if (sum == 100) break;
	} while (next_permutation(v.begin(), v.end()));

	for (int i = 0; i < 7; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
