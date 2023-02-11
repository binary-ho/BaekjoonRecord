#include <iostream>
#include <stack>
#include <string>


std::string check(std::string str) {
	int i = 0;
	for (auto elem : str) {
		if (elem == '(') {
			i++;
		}
		else if (elem == ')') {
			i--;
		}
		if (i < 0)
		{
			return "NO";
		}

	}
	if (i==0)
	{
		return "YES";
	}
	else {
		return "NO";
	}

}

//using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	std::cin.ignore();
	while (t--) {
		std::string str;
		std::cin >> str;
		std::cout<<check(str)<<'\n';
	}
	return 0;
}