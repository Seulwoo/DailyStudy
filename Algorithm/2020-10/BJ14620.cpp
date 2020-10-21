#include <iostream>
#define MIN(a,b) a<b?a:b
using namespace std;


int move_i[5] = { -1,1,0,0,0 }; // 총 다섯칸!
int move_j[5] = { 0, 0, -1,1,0 };
int N, G[10][10];
int min_value = 5000;
void DFS(int i, int j, int cnt, int cost, int visit[10][10]) {
	for (int d = 0; d < 5; d++) { // 꽃을 심을 수 없으면 pass
		if (visit[i + move_i[d]][j + move_j[d]] != 0)
			return;
	}
	int new_cost = cost;
	for (int d = 0; d < 5; d++) { // 다섯 칸의 가격 더하기
		int n_i = i + move_i[d], n_j = j + move_j[d];
		visit[n_i][n_j] = 1;
		new_cost += G[n_i][n_j];
	}

	if (cnt >= 2) { // 세개의 꽃을 심었을 경우
		min_value = MIN(new_cost, min_value);
		for (int d = 0; d < 5; d++) {
			int n_i = i + move_i[d], n_j = j + move_j[d];
			visit[n_i][n_j] = 0; // visit 배열 초기화
		}
		return; // 종료~
	}

	for (int ii = 1; ii < N-1; ii++) {
		for (int jj = 1; jj < N - 1; jj++) {
			if (visit[ii][jj] == 0)
				DFS(ii, jj, cnt+1, new_cost, visit);
		}
	}

	for (int d = 0; d < 5; d++) {
		int n_i = i + move_i[d], n_j = j + move_j[d];
		visit[n_i][n_j] = 0; // visit 배열 초기화
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &G[i][j]);
		}
	}

	int visit[10][10] = { 0, };
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			DFS(i, j, 0, 0, visit);
		}
	}

	printf("%d", min_value);
}
