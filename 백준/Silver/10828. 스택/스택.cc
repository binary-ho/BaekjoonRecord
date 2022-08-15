#include <iostream>
#include <string>

//using namespace std;

struct Stack {
	
	int data[10000];
	int size;

	Stack() {
		size = 0;
	}
	void push(int num)
	{
		data[size] = num;
		size++;
	}
	int pop() {
		if (size == 0) {
			return -1;
		}
		else {
			size--;
			return data[size];
		}
	}
	int empty() {
		if (size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int top() {
		if (size == 0) {
			return -1;
		}
		else {
			return data[size-1];
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	std::cin.ignore();
	Stack stack1;
	while (t--) {
		std::string str;
		std::cin >> str;
		if (str == "push") {
			int num;
			std::cin >> num;
			stack1.push(num);
		}
		else if (str == "pop") {
			std::cout << stack1.pop()<< '\n';
		}
		else if (str == "top") {
			std::cout << stack1.top() << '\n';
		}
		else if (str == "empty") {
			std::cout << stack1.empty() << '\n';
		}
		else if (str == "size") {
			std::cout << stack1.size << '\n';
		}
	}
	
}