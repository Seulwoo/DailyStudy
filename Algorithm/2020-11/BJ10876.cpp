#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	bool pos_flag[1001] = { 0, }; // 양수 플래그
	bool neg_flag[1001] = { 0, }; // 음수 플래그
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp >= 0)
			pos_flag[tmp] = true;
		else
			neg_flag[-tmp] = true;
	}
	for (int i = 1000; i > 0; i--) {
		if (neg_flag[i])
			cout << -i << " ";
	}
	for (int i = 0; i <= 1000; i++) {
		if (pos_flag[i])
			cout << i << " ";
	}

	return 0;
}
