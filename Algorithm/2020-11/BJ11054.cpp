#include <iostream>
#define endl '\n'
#define MAX(a,b) a>b?a:b
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[1001] = { 0, };
	int forward[1001] = { 0, }; // 증가하는 부분 순열
	int backward[1001] = { 0, }; // 감소하는 부분 순열
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (forward[i] == 0)
			forward[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				forward[j] = MAX(forward[j], forward[i] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (backward[i] == 0)
			backward[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				backward[j] = MAX(backward[j], backward[i] + 1);
			}
		}
	}

	int max_answer = -1;
	for (int i = 0; i < n; i++) {
		max_answer = MAX(max_answer, forward[i] + backward[i]);
	}
	cout << max_answer - 1 << endl;

	return 0;
}
