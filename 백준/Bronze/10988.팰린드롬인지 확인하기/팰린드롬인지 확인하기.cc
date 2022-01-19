#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> str;
	bool flag = true;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) {
			flag = false;
			break;
		}
	}

	if (flag) cout << 1;
	else cout << 0;
	return 0;
}
