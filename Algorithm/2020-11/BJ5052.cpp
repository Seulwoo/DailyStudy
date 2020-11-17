#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t-- > 0) {
		string s;
		string ss[10000];
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			ss[i] = s;
		}
		sort(ss, ss + n);
		bool flag = false;
		for (int i = 0; i < n - 1; i++) {
			if (ss[i].length() < ss[i + 1].length()) {
				if (ss[i] == ss[i + 1].substr(0, ss[i].length())) {
					flag = true;
					break;
				}
			}
		}
		if (flag)
			cout << "NO" << endl; // 일관성이 없는 경우
		else
			cout << "YES" << endl; // 일관성이 있는 경우
	}
	return 0;
}
