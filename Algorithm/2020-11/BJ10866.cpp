#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	deque<int> deq;
	string op;
	int operand;
	for (int i = 0; i < N; i++) {
		cin >> op;
		if (op == "push_front") {
			cin >> operand;
			deq.push_front(operand);
		}
		else if (op == "push_back") {
			cin >> operand;
			deq.push_back(operand);
		}
		else if (op == "pop_front") {
			if (deq.empty())
				cout << -1 << endl;
			else {
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (op == "pop_back") {
			if (deq.empty())
				cout << -1 << endl;
			else {
				cout << deq.back() << endl;
				deq.pop_back();
			}

		}
		else if (op == "size") {
			cout << deq.size() << endl;
		}
		else if (op == "empty") {
			cout << deq.empty() << endl;
		}
		else if (op == "front") {
			if (deq.empty())
				cout << -1 << endl;
			else
				cout << deq.front() << endl;
		}
		else if (op == "back") {
			if (deq.empty())
				cout << -1 << endl;
			else
				cout << deq.back() << endl;
		}

	}
	return 0;
}
