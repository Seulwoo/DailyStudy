#include <iostream>
#include <vector>
#define MIN(a,b) a<b?a:b
using namespace std;
int map[50][50];
pair<int, int> chicken_list[13];

int move_x[4] = { 0, 0, -1, 1 };
int move_y[4] = { -1, 1, 0, 0 };
int N, M, S = 0;
int answer = 11111;

int chicken_distance() { // 치킨 거리 계산
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				int min_chicken = 11111;
				for (int idx = 0; idx <= S; idx++) {
					int c_i = chicken_list[idx].first, c_j = chicken_list[idx].second;
					if (map[c_i][c_j] == 2) {
						int h = c_i - i, w = c_j - j;
						if (h < 0)
							h *= -1;
						if (w < 0)
							w *= -1;
						min_chicken = MIN(min_chicken, h + w);
					}
				}
				sum += min_chicken;
			}
		}
	}
	return sum;
}

void select(int idx, int cnt) {
	if (cnt >= S - M) {
		int result = chicken_distance();
		answer = MIN(answer, result);
		return;
	}

	for (int i = idx; i < S; i++) {
		int cur_i = chicken_list[i].first, cur_j = chicken_list[i].second;
		if (map[cur_i][cur_j] == 0)
			continue;
		map[cur_i][cur_j] = 0;
		select(i, cnt + 1);
		map[cur_i][cur_j] = 2;
	}
}

int main() {

	scanf("%d %d", &N, &M);
	
	int t = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chicken_list[S++] = { i,j };
			}
		}
	}

	select(0,0);
	printf("%d\n", answer);
}
