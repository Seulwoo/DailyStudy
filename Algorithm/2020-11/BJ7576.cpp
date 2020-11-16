#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int box[1000][1000] = { 0, };
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;


	int counts = 0;
	queue<pair<int,pair<int, int>>> bfs_que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				bfs_que.push({ 0,{ i, j } });
				++counts;
			}
			else if (box[i][j] == -1) {
				++counts;
			}
		}
	}

	int move_i[4] = { 0, 0, -1, 1 };
	int move_j[4] = { -1, 1, 0, 0 };
	int answer = 0;
	while (!bfs_que.empty()) {
		int i = bfs_que.front().second.first, j = bfs_que.front().second.second;
		answer = bfs_que.front().first;
		bfs_que.pop();

		for (int d = 0; d < 4; d++) {
			int new_i = i + move_i[d], new_j = j + move_j[d];
			if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > M - 1)
				continue;
			if (box[new_i][new_j] == 0) {
				box[new_i][new_j] = 1;
				bfs_que.push({ answer + 1, {new_i, new_j} });
				++counts;
			}
		}
	}
	
	if (counts == N * M)
		cout << answer << endl;
	else
		cout << -1 << endl;


	return 0;
}
