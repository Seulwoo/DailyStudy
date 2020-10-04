#include <iostream>
#include <queue>

using namespace std;
int visit[1000001] = { 0, };

int main(void) {

	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	int answer = -1;
	queue<int> bfs_queue;
	bfs_queue.push(S);
	visit[S] = 1;

	while (!bfs_queue.empty()) {
		int cur = bfs_queue.front();
		bfs_queue.pop();
		if (cur == G) {
			answer = visit[cur];
			break;
		}

		int up = cur + U, down = cur - D;
		if (up == G || down == G) {
			answer = visit[cur] + 1;
			break;
		}

		if (up <= F && visit[up] == 0) { // UP 버튼
			bfs_queue.push(up);
			visit[up] = visit[cur]+1;
		}

		if (down >= 1 && visit[down] == 0) { // DOWN 버튼
			bfs_queue.push(down);
			visit[down] = visit[cur]+1;
		}
	}

	answer == -1 ? printf("use the stairs") : printf("%d", answer-1);
}
