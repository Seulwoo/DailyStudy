#include <iostream>
using namespace std;


int main() {
	int R, C, T;
	scanf("%d %d %d", &R, &C, &T);
	
	int room[50][50];
	int air_i = -1, air_j = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &room[i][j]);
			if (room[i][j] == -1 && air_i == -1) {
				air_i = i, air_j = j;
			}
		}
	}

	while (T-- > 0) {
		int dust[50][50] = { 0, };
		for (int i = 0; i < R; i++) { // 미세먼지가 한 번에 확장되기 위해 저장
			for (int j = 0; j < C; j++) {
				if (room[i][j] > 0) {
					int cnt = 0;
					if (i - 1 >= 0 && room[i - 1][j] >= 0) {
						cnt++;
						dust[i - 1][j] += (room[i][j] / 5);
					}

					if (i + 1 <= R - 1 && room[i + 1][j] >= 0) {
						cnt++;
						dust[i + 1][j] += (room[i][j] / 5);
					}

					if (j - 1 >= 0 && room[i][j - 1] >= 0) {
						cnt++;
						dust[i][j - 1] += (room[i][j] / 5);
					}

					if (j + 1 <= C - 1 && room[i][j + 1] >= 0) {
						cnt++;
						dust[i][j + 1] += (room[i][j] / 5);
					}

					room[i][j] -= (room[i][j] / 5)*cnt;
				}
			}
		}

		for (int i = 0; i < R; i++) { // 미세먼지 확장
			for (int j = 0; j < C; j++) {
				if (room[i][j] >= 0) {
					room[i][j] += dust[i][j];
				}
			}
		}

		int t_i = air_i - 1, t_j = air_j; // 공기 청정기 회전
		while (t_i > 0) {
			room[t_i][t_j] = room[t_i - 1][t_j];
			t_i--;
		}
		while (t_j < C - 1) {
			room[t_i][t_j] = room[t_i][t_j + 1];
			t_j++;
		}
		while (t_i < air_i) {
			room[t_i][t_j] = room[t_i + 1][t_j];
			t_i++;
		}
		while (t_j > 1) {
			room[t_i][t_j] = room[t_i][t_j - 1];
			t_j--;
		}
		room[t_i][t_j] = 0;

		t_i = air_i + 2, t_j = air_j;
		while (t_i < R - 1) {
			room[t_i][t_j] = room[t_i + 1][t_j];
			t_i++;
		}
		while (t_j < C - 1) {
			room[t_i][t_j] = room[t_i][t_j + 1];
			t_j++;
		}
		while (t_i > air_i + 1) {
			room[t_i][t_j] = room[t_i - 1][t_j];
			t_i--;
		}
		while (t_j > 1) {
			room[t_i][t_j] = room[t_i][t_j - 1];
			t_j--;
		}
		room[t_i][t_j] = 0;

	}

	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			sum += room[i][j];
		}
	}
	printf("%d\n", sum+2);
}
