#include <iostream>
#include <string>
#include <vector>


struct Queue {
	int start;
	int end;
	std::vector<int> que;
	Queue() {
		start = 0;
		end = 0;
	}
	void push() {
		int input;
		std::cin >> input;
		que.push_back(input);
		end++;
	}
	int pop() {
		if (start != end) {
			start++;
			return que[start-1];
			//이거 안 되면 start++ 하고 que[start-1]
		}
		else { return -1; }
	}
	int size() { return end - start; }
	int empty() {
		if (start == end) {return 1;}
		else { return 0; }
	}
	int front() { 
		if (start != end) { return que[start]; }
		else { return -1; }
	}
	int back() {
		if (start != end) { return que[end-1]; }
		else { return -1; }
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	std::cin.ignore();
	Queue que;

	while (t--) {
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "push") {
			que.push();
		}
		else if(cmd == "pop") {
			std::cout<< que.pop()<<'\n';
		}
		else if(cmd == "size") {
			std::cout << que.size() << '\n';
		}
		else if(cmd == "empty") {
			std::cout << que.empty() << '\n';
		}
		else if (cmd == "front") {
			std::cout << que.front() << '\n';
		}
		else if (cmd == "back") {
			std::cout << que.back() << '\n';
		}
	}
}