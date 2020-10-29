#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main() {
	int N;
	cin >> N;
	
	int pos[1001] = { 0, };
	int neg[1001] = { 0, };
	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num >= 0) {
			pos[num] = 1; // 양수 저장
		}
		else {
			neg[-num] = 1; // 음수 저장
		}
	}

	for (int i = 1000; i > 0; i--) {
		if (neg[i])
			cout << -i << endl;
	}
	for (int i = 0; i <= 1000; i++) {
		if (pos[i])
			cout << i << endl;
	}
}
