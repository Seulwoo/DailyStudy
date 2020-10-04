#include <iostream>
#include <vector>
#include <queue>
#define max(a,b) a>b?a:b

using namespace std;
int N, M;
int inputs[301];

bool check(int mid) { // 기준값으로 구슬을 나눌 수 있는지 체크
	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += inputs[i];
		if (sum > mid) { cnt++; sum = inputs[i]; }
		if (cnt > M) { return false; }
	}
	return true;
}

int main(void) {
	scanf("%d %d", &N, &M);
	int max = -1, sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &inputs[i]);
		sum += inputs[i];
		if (inputs[i] > max) max = inputs[i];
	}

	int left = max, right = sum, mid; // left값을 최대값 right값을 합
	int res = 0;

	while (left < right) {
		mid = (left + right) / 2;
		if (check(mid)) {
			right = mid;
			res = mid;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d\n", res);

	int cnt = 1, num = 0;
	sum = 0;
	for (int i = 0; i < N; i++) {
		sum += inputs[i];
		if (sum > res) {
			cnt++;
			sum = inputs[i];
			printf("%d ", num);
			num = 0;
		}
		num++;
		if ((M - cnt) == (N - i - 1)) {
			printf("%d ", num);
			break;
		}
	}
	for (int i = 0; i < (M - cnt); i++) {
		printf("1 ");
	}
}
