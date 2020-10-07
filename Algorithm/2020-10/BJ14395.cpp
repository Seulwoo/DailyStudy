#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

int main(void) {
	long long s, t;
	scanf("%lld %lld", &s, &t);

	if (s == t) {
		cout << 0;
		return 0;
	}

	map<long long, string> visit;
	queue<long long> bfs_queue;
	bfs_queue.push(s);
	visit[s] = "";

	while (!bfs_queue.empty()) {
		long long cur = bfs_queue.front();
		string save = visit[cur];
		bfs_queue.pop();

		if (cur == t)
			break;

		if (cur * cur <= t && visit.count(cur*cur) == 0) {
			visit[cur*cur] = save + "*";
			bfs_queue.push(cur*cur);
		}
		if (cur + cur <= t && visit.count(cur + cur) == 0) {
			visit[cur + cur] = save + "+";
			bfs_queue.push(cur + cur);
		}
		if (cur != 0 && visit.count(1) == 0) {
			visit[1] = save + "/";
			bfs_queue.push(1);
		}
	}

	if (visit.count(t) == 0) {
		cout << -1;
		return 0;
	}
	else {
		cout << visit[t];
	}
}
