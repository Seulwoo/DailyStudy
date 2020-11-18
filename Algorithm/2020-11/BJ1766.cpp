#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int precedes[32001] = { 0, };
	vector<int> nexts[32001];

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B; // A를 B보다 먼저 풀기
		++precedes[B];
		nexts[A].push_back(B);
	}

	priority_queue<int, vector<int>, greater<int>> orderQueue;
	for (int i = 1; i <= N; i++) {
		if (precedes[i] == 0)
			orderQueue.push(i);
	}

	while (!orderQueue.empty()) {
		int cur = orderQueue.top();
		orderQueue.pop();
		cout << cur << " ";

		int cur_size = nexts[cur].size();
		for (int c = 0; c < cur_size; c++) {
			int next = nexts[cur][c];
			--precedes[next];
			if (precedes[next] == 0)
				orderQueue.push(next);
		}
	}

	return 0;
}
