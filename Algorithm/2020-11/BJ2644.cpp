#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = -1;
	int n, a, b, m;
	cin >> n >> a >> b >> m; // a 와 b가 몇촌인지 구해야 한다

	vector<int> node[101];

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}

	queue<pair<int, int>> search_queue; // bfs 큐
	int check[101] = { 0, }; // 지나갔는지 확인하는 배열

	search_queue.push({ a, 0 }); // 현재 노드, 촌수
	check[a] = 1;
	while (!search_queue.empty()) {
		int cur = search_queue.front().first, dist = search_queue.front().second;
		search_queue.pop();
		if (cur == b) {
			answer = dist;
			break;
		}
		
		int cur_size = node[cur].size();
		for (int i = 0; i < cur_size; i++) {
			int next = node[cur][i];
			if (!check[next]) {
				search_queue.push({ next, dist + 1 });
				check[next] = 1;
			}
		}
	}

	cout << answer << endl;
	return 0;
}
