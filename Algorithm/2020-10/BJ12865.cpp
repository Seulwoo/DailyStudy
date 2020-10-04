#include <iostream>
#include <vector>
#define max(a,b) a>b?a:b

using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K); // 물품의 수, 버틸 수 있는 무게

	int W, V;
	vector<pair<int, int>>  inputs;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &W, &V); // 물품의 무게와 가치
		inputs.push_back({ W, V }); // inputs[i].first = 무게, inputs[i].second = 가치
	}

	int bags[101][100001] = { {0,} }; // DP 배열
	int answer = -1;

	for (int i = 1; i < N + 1; i++) { // knapsack 알고리즘
		for (int j = 1; j < K + 1; j++) {
			if (inputs[i - 1].first <= j) {
				bags[i][j] = max(bags[i - 1][j], bags[i - 1][j - inputs[i - 1].first] + inputs[i - 1].second);
			}
			else {
				bags[i][j] = bags[i - 1][j];
			}
			answer = max(answer, bags[i][j]); // max value 업데이트
		}
	}


	printf("%d", answer);
}
