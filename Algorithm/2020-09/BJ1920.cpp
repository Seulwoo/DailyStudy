#include <iostream>
#include <algorithm>

using namespace std;

long long inputs[100000];
long long numbers[100000];
int main(void) {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &numbers[i]);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld", &inputs[i]);
	}

	sort(numbers, numbers+N); // 정렬
	for (int i = 0; i < M; i++) {
		if (binary_search(numbers, numbers + N, inputs[i])) { // 이진탐색
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}
