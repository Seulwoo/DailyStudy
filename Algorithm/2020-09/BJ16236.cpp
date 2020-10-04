#include <iostream>
#include <vector>
#include <queue>
#define max(a,b) a>b?a:b

using namespace std;
int move_x[4] = { 0,0,-1,1 };
int move_y[4] = { -1,1,0,0 };

int main(void) {
	
	int baby_x, baby_y, baby_size = 2, baby_cnt = 0;
	int fish[20][20];
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &fish[i][j]);
			if (fish[i][j] == 9) { // 아기 상어의 위치
				baby_x = i, baby_y = j;
			}
		}
	}

	bool flag = true;
	int answer = 0;
	while (flag) { // 먹을 수 있는 물고기가 없을 때까지
		int visit[20][20] = { {0,} };
		queue<pair<int, int>> fish_que;
		flag = false;
		int dist = 1;
		int eat_dist = -1, eat_x = -1, eat_y = -1;

		fish_que.push({ baby_x, baby_y });
		visit[baby_x][baby_y] = dist;
		while (!fish_que.empty()) { // BFS 큐를 이용해 최단거리 물고기 위치를 구함
			int cur_x = fish_que.front().first, cur_y = fish_que.front().second;
			fish_que.pop();

			dist = visit[cur_x][cur_y] + 1;
			if (eat_dist > 0 && eat_dist < dist) {
				break;
			}
			for (int i = 0; i < 4; i++) {
				int new_x = cur_x + move_x[i], new_y = cur_y + move_y[i];
				if (new_x<0 || new_x>N - 1 || new_y<0 || new_y>N - 1)
					continue;
				if (visit[new_x][new_y] != 0) {
					continue;
				}
				if (fish[new_x][new_y] == 0) {
					fish_que.push({ new_x, new_y });
					visit[new_x][new_y] = dist;
				}
				else if (fish[new_x][new_y] > baby_size) {
					continue;
				}
				else if (fish[new_x][new_y] == baby_size) {
					fish_que.push({ new_x, new_y });
					visit[new_x][new_y] = dist;
				}
				else {
					flag = true;
					if (eat_dist == -1) {
						eat_dist = dist;
						eat_x = new_x, eat_y = new_y;
					}
					else if (new_x < eat_x) { // 가장 위쪽의 물고기
						eat_x = new_x, eat_y = new_y;
					}
					else if (new_x == eat_x && new_y < eat_y) { // 가장 왼쪽의 물고기
						eat_x = new_x, eat_y = new_y;
					}				
				}
			}
		}
		if (flag) {
			fish[baby_x][baby_y] = 0;
			fish[eat_x][eat_y] = 9;
			baby_x = eat_x, baby_y = eat_y; // 아기상어 위치 업데이트
			answer += (eat_dist-1); // 움직인 거리의 합 (시간)
			baby_cnt++;
			if (baby_cnt == baby_size) { // 상어의 크기만큼 물고기를 먹었을 경우
				baby_size++;
				baby_cnt = 0;
			}
		}	
	}
	printf("%d\n", answer);
}
