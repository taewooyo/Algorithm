#include<bits/stdc++.h>   
using namespace std;   
typedef long long ll;   

int T, n;
string P, order;
deque<int> q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> P >> n >> order;
		int temp = 0;
		q.clear();
		for(char c : order) {
			if(c == '[' || c == ']') continue;
			if(c >= '0' && c <= '9') {
				temp = temp * 10 + c - '0';
			}
			else {
				if(temp != 0) q.push_back(temp);
				temp = 0;
			}
		}
		if(temp != 0) q.push_back(temp);
		
		bool error = false;
		bool rev = false;
		for (char c : P) {
			if(c == 'R') {
				rev = !rev;
			}
			else {
				if(q.size() == 0) {
					error = true;
					break;
				}
				if(rev) q.pop_back();
				else q.pop_front();
			}
		}
		if(error) cout << "error\n";
		else {
			cout << "[";
			if(rev) reverse(q.begin(), q.end());
			for (int i = 0; i < q.size(); i++) {
				cout << q[i];
				if(i < q.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
	}
} 