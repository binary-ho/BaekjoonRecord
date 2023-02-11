#include<iostream>
#include <string>
#include <stack>
#include <vector>
//#include <algorithm>
//#include <queue>
//#include<cmath>
using namespace std;
//int A[501][501];
char D[100];
double P[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, count = 0, done = 0, out = 0;
	cin >> N;
	string s;
	cin >> s;
	/*for (int i = 1; out!=1;i++) {

		
		length++;
		if (D[i] <= 90 && 65 <= D[i]) {
			count++;
			if (D[i] - 64 == N) {
				done++;
			}
		}
		else if(D[i] == '+' || D[i] == '-' || D[i] == '*' || D[i] == '/'){
			count--;
		}
		if (count == 1 && done >= 1) {
			out++;
		}
	}*/
	//cout << s[1] << ' '<< s[2];
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		//cout << P[i] << ' ';
	}
	stack<double> stack_1;
	int length = s.length();
	int call_P = 1;
	int call_alpha = 65;
	double save_me;
	for (int i = 0; i < length; i++) {
		if(s[i] == '+'){
			double num_1 = stack_1.top();
			//cout << num_1 << "is num_1, now +" << '\n';
			stack_1.pop();
			double num_2 = stack_1.top();
			//cout << num_2 << "is num_2" << '\n';
			stack_1.pop();
			save_me = num_2 + num_1;
			//cout << save_me << "is the answer" << '\n';
			stack_1.push(save_me);
		}
		else if (s[i] == '-') {
			double num_1 = stack_1.top();
			//cout << num_1 << "is num_1, now -" << '\n';
			stack_1.pop();
			double num_2 = stack_1.top();
			//cout << num_2 << "is num_2" << '\n';
			stack_1.pop();
			save_me = num_2 - num_1;
			//cout << save_me << "is the answer" << '\n';
			stack_1.push(save_me);
		}
		else if (s[i] == '*') {
			double num_1 = stack_1.top();
			//cout << num_1 << "is num_1, now *" << '\n';
			stack_1.pop();
			double num_2 = stack_1.top();
			//cout << num_2 << "is num_2" << '\n';
			stack_1.pop();
			save_me = num_2 * num_1;
			//cout << save_me << "is the answer" << '\n';
			stack_1.push(save_me);
		}
		else if (s[i] == '/') {
			double num_1 = stack_1.top();
			//cout << num_1 << "is num_1, now /" << '\n';
			stack_1.pop();
			double num_2 = stack_1.top();
			//cout << num_2 << "is num_2" << '\n';
			stack_1.pop();
			save_me = num_2 / num_1;
			//cout << save_me << "is the answer" << '\n';
			stack_1.push(save_me);
		}
		else if (s[i] <= 90 && 65<= s[i]) {
			stack_1.push(P[(int)s[i] - 65]);
			//cout << P[call_alpha - 64] << "is pushed" << '\n';
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stack_1.top();
}