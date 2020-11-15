#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int vip[41] = { 0, };
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		vip[tmp] = 1;
	}

	long long arr[41] = { 0, };
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1];
		if (vip[i] == 0 && vip[i - 1] == 0)
			arr[i] += (arr[i - 2]);
	}
	cout << arr[N] << endl;
	return 0;
}
