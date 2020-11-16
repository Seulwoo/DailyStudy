#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[50] = { 0, };
	int p = 1;
	for (int i = 1; i <= 49; i++) { // 각 번호의 시작값
		arr[i] = p;
		p += i;
	}

	int A, B;
	cin >> A >> B;

	long long answer = 0;
	int cur = 1;
	while (true) {
		if (arr[cur] <= A && arr[cur + 1] > A)
			break;
		++cur;
	}
	while (A <= B) {
		if (arr[cur + 1] <= A)
			++cur;
		answer += cur;
		++A;
	}

	cout << answer << endl;
	return 0;
}
