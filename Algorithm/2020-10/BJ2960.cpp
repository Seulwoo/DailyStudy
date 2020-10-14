#include <iostream>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int num[1001] = { 0, };
	for (int i = 2; i <= N; i++) {
		if (num[i] == 1)
			continue;
		for (int j = 1; i*j <= N; j++) {
			if (num[i*j] == 0) {
				num[i*j] = 1;
				K--;
				if (K <= 0) { // K번째 수
					printf("%d\n", i*j);
					return 0;
				}
			}
		}
	}
}
