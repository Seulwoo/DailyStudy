#include <iostream>
#define endl '\n'
#define MAX(a,b) a>b?a:b
using namespace std;

int prime[4000001] = { 0, };
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	prime[0] = 1, prime[1] = 1;
	for (int i = 2; i <= N; i++) { // 프라임 배열에 소수여부 체크
		if (prime[i])
			continue;
		for (int j = 2; i*j <= N; j++) {
			prime[i*j] = 1; // 1이면 소수가 아님
		}
	}

	int answer = 0;
	int begin = 2, end = 2, sum = 2; // 시작포인터, 끝 포인터
	while (sum < N) { // 초기 끝 포인터 설정
		end++;
		while (prime[end]) {
			end++;
		}
		sum += end;
	}
	
	while (begin <= end) {
		if (sum == N) { // 연속된 소수의 합이 N과 같으면 answer 증가
			answer++;
		}
		
		if (sum >= N) { // 시작 포인터 증가
			sum -= begin;
			begin++;
			while (prime[begin]) {
				begin++;
			}
		}
		else if (sum < N) { // 끝 포인터 감소
			end++;
			while (prime[end]) {
				end++;
			}
			sum += end;
		}
	}
	
	cout << answer << endl;
	return 0;
}
