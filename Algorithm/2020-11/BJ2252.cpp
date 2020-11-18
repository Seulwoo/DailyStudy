#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int prevs[32001] = { 0, };
	vector<int> nexts[32001];

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		++prevs[B]; // B앞에 A가 나와야 한다
		nexts[A].push_back(B); // A뒤에 B가 나온다
	}

	queue<int> orderQueue;
	for (int i = 1; i <= N; i++) {
		if (prevs[i] == 0) // 선조건이 없는 학생들을 큐에 넣는다
			orderQueue.push(i);
	}
	while (!orderQueue.empty()) {
		int cur = orderQueue.front();
		orderQueue.pop();

		cout << cur << " ";

		int cur_size = nexts[cur].size();
		for (int j = 0; j < cur_size; j++) {
			int next = nexts[cur][j];
			--prevs[next];
			if (prevs[next] == 0)
				orderQueue.push(next);
		}
	}
	return 0;
}
