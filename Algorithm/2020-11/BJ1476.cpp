#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int E, S, M;
	cin >> E >> S >> M;

	if (E == 15) E = 0;
	if (S == 28) S = 0;
	if (M == 19) M = 0;

	long long cur = S;
	if (cur == 0) cur += 28;
	while (true) {
		if (cur % 15 == E && cur % 19 == M) {
			break;
		}
		else {
			cur += 28;
		}
	}
	cout << cur;
	return 0;
}
