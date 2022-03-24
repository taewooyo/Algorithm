#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int n, cnt;
int map[25][25];
bool visited[25][25];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<int> answer;
void dfs(int y, int x) {
	cnt++;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (map[ny][nx] == 1 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);

				answer.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	
	for (auto a : answer) {
		cout << a << '\n';
	}
	
}