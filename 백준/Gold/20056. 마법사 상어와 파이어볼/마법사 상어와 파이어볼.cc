#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#define MAX 50
#define DIR 8
using namespace std;

vector<tuple<int, int, int> > grid[MAX][MAX];
vector<tuple<int, int, int> > next_grid[MAX][MAX];

int N, M, K;


/*

nn격자에 m개의 파이어볼이 존재
m개의 파이어볼은 (y, x, 질량m, 방향d 속력s)의 속성을 가지고 있다.
1번은 n번가 연결되어있다.

1. 모든 파이어볼은 자신의 방향으로 d로 s만큼 이동한다. 이동 중 같은칸 에 여러 파이어볼이 존재할 수 있음
	1.1 n번의 다음 칸은 1이다..
2. 이동이 끝난 후,
	2.1 2개의 파이어볼을 가지고 있는 칸은,
	2.2 파이어볼은 4개의 파이어볼로 나뉜다.
	2.3 나누어진 파이어볼의 속성은
		2.3.1 질량은 합쳐진 파이어볼 질량의 합/5
		2.3.2 속력은 합쳐진 파이어볼 속력의 합/파이어볼 개수
		2.3.3 합쳐진 파이어볼의 방향이 모두 홀수이거나, 짝수라면 방향은 0246 그것이 아니라면 1,3,5,7
	질량이 0인 곳은 소멸된다.

	K번 후 남이 있는 파이어볼의 질량은?

*/

bool InRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

pair<int, int> NextPos(int y, int x, int s, int d) {
	int dy[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
	int dx[] = { 0,  1, 1, 1, 0, -1, -1, -1 };

	// 움직인 이후 값이 음수가 되는 경우, 이를 양수로 쉽게 만들기 위해서는
	// n의 배수이며 더했을 때 값을 항상 양수로 만들어 주는 수인 nv를 더해주면 됩니다.
	int ny = (y + dy[d] * s + N * s) % N;
	int nx = (x + dx[d] * s + N * s) % N;

	return make_pair(ny, nx);
}

void MoveAll() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			next_grid[i][j].clear();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j].size() == 0) continue;
			for (int k = 0; k < grid[i][j].size(); k++) {
				int m, s, d;
				tie(m, s, d) = grid[i][j][k];

				int ny, nx;
				tie(ny, nx) = NextPos(i, j, s, d);
				next_grid[ny][nx].push_back(make_tuple(m, s, d));
			}
		}
	}
}

void DivideFireball(int y, int x) {
	/*
	2. 이동이 끝난 후,
		2.1 2개의 파이어볼을 가지고 있는 칸은,
		2.2 파이어볼은 4개의 파이어볼로 나뉜다.
		2.3 나누어진 파이어볼의 속성은
		2.3.1 질량은 합쳐진 파이어볼 질량의 합 / 5
		2.3.2 속력은 합쳐진 파이어볼 속력의 합 / 파이어볼 개수
		2.3.3 합쳐진 파이어볼의 방향이 모두 홀수이거나, 짝수라면 방향은 0246 그것이 아니라면 1, 3, 5, 7
		질량이 0인 곳은 소멸된다.
	*/
	int sum_mass = 0;
	int sum_speed = 0;
	int odd_cnt = 0, even_cnt = 0;
	for (int i = 0; i < next_grid[y][x].size(); i++) {
		int m, s, dir;
		tie(m, s, dir) = next_grid[y][x][i];
		sum_mass += m;
		sum_speed += s;
		if (dir % 2 == 0) {
			even_cnt++;
		}
		else
			odd_cnt++;
	}

	int base = 0;
	if (even_cnt == 0 || odd_cnt == 0)
		base = 0;
	else base = 1;

	for (int i = base; i < 8; i += 2) {
		int avg = sum_mass / 5;
		if (avg != 0) {
			grid[y][x].push_back(make_tuple(sum_mass / 5, sum_speed / next_grid[y][x].size(), i));
		}
	}
}

void Simulate() {
	MoveAll();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			grid[i][j].clear();
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (next_grid[i][j].size() == 1)
				grid[i][j].push_back(next_grid[i][j][0]);
			else {
				DivideFireball(i, j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		grid[r - 1][c - 1].push_back(make_tuple(m, s, d));
	}

	while (K--) {
		Simulate();
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < grid[i][j].size(); k++) {
				int m;
				tie(m, ignore, ignore) = grid[i][j][k];
				answer += m;
			}
		}
	}
	cout << answer;
	return 0;
}