#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	queue<int> print_que; // 테이블 큐
	for (int i = 1; i <= N; i++) {
		print_que.push(i);
	}

	vector<int> answer; // 정답 큐
	while (!print_que.empty()) {
		for (int i = 0; i < K - 1; i++) { // K번째 수를 찾기 위해
			int tmp = print_que.front();
			print_que.pop();
			print_que.push(tmp);
		}
		int tmp = print_que.front();
		print_que.pop();
		answer.push_back(tmp);
	}

	printf("<");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ",answer[i]);
	}
	printf("%d>", answer[N - 1]);
}
