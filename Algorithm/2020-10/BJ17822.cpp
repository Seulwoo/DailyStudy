#include <iostream>
#include <vector>

#define MAX(a,b) a>b?a:b
using namespace std;

int main() {
	int N, M, T;
	scanf("%d %d %d", &N, &M, &T);
	
	int board[51][51] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	int top[51] = { 0, }; // 원판의 12시 방향을 가르키는 
	for (int i = 1; i <= N; i++) {
		top[i] = 1;
	}

	while (T-- > 0) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);
		for (int i = x; i <= N; i += x) {
			if (d == 1) {
				top[i] += k;
				if (top[i] > M) top[i] -= M;
			}
			else {
				top[i] -= k;
				if (top[i] < 1) top[i] += M;
			}
		}
		
		bool check[51][51] = { 0, };
		bool avg_flag = false;
		for (int i = 1; i <= N; i++) {
			int top_pointer = top[i];
			int down_pointer = top[i - 1];
			int cnt = M;
			while (cnt-- > 0) {
				int right = top_pointer + 1;
				if (right > M) right -= M;
				if (board[i][top_pointer] > 0 && board[i][top_pointer] == board[i - 1][down_pointer]) {
					check[i][top_pointer] = true;
					check[i - 1][down_pointer] = true;
					avg_flag = true;
				}
				if (board[i][top_pointer] > 0 && board[i][top_pointer] == board[i][right]) {
					check[i][top_pointer] = true;
					check[i][right] = true;
					avg_flag = true;
				}
				if (++top_pointer > M) top_pointer -= M;
				if (++down_pointer > M) down_pointer -= M;
			}
		}
		if (!avg_flag) {
			int sum = 0;
			int cnt = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (board[i][j] > 0) {
						sum += board[i][j];
						cnt++;
					}
				}
			}
			float avg = (float)sum / cnt;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (board[i][j] > 0 && ((float)board[i][j]-avg) > 0)
						board[i][j] -= 1;
					else if (board[i][j] > 0 && ((float)board[i][j]-avg) < 0)
						board[i][j] += 1;
				}
			}
		}
		else {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (check[i][j]) {
						board[i][j] = 0;
					}
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			answer += board[i][j];
		}
	}
	printf("%d\n", answer);
}
