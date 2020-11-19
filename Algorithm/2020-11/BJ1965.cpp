#include <iostream>
#define endl '\n'
#define MAX(a,b) a>b?a:b
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int sizes[1001] = { 0, };
	int dp[1001] = { 0, };
	for (int i = 0; i < n; i++)
		cin >> sizes[i];

	int max_value = -1;
	for (int i = 0; i < n; i++) {
        dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (sizes[j] < sizes[i])
				dp[i] = MAX(dp[i], dp[j] + 1);
		}
		max_value = MAX(max_value, dp[i]);
	}

	cout << max_value << endl;

	return 0;
}
