#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int move_i[4] = { 0, 0, -1, 1 };
int move_j[4] = { -1, 1, 0, 0 };
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int map[25][25] = { 0, };
	int cnt = 0;
	vector<int> sizes;

	cin >> N;
	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			map[i][j] = tmp-'0';
		}
	}

	queue<pair<int, int>> que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) {
				int cur_size = 0;
				++cnt;

				que.push({ i, j });
				map[i][j] = 0;
				while (!que.empty()) {
					cur_size++;
					int cur_i = que.front().first, cur_j = que.front().second;
					que.pop();

					for (int d = 0; d < 4; d++) {
						int new_i = cur_i + move_i[d], new_j = cur_j + move_j[d];
						if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1)
							continue;
						if (map[new_i][new_j]) {
							que.push({ new_i,new_j });
							map[new_i][new_j] = 0;
						}
					}
				}
				sizes.push_back(cur_size);
			}

		}
	}
	sort(sizes.begin(), sizes.end());
	cout << cnt << endl;
	for (int i = 0; i < sizes.size(); i++) {
		cout << sizes[i] << endl;
	}
	

	return 0;
}
