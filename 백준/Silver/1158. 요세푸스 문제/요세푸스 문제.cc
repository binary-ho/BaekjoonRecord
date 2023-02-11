#include <iostream>
#include <string>
#include <queue>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::queue<int> que;
	int N, K;
	std::cin >> N;
	std::cin >> K;

	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	std::cout << "<";
	for(int k=0;k<N-1;k++)
	{
		for (int i = 0; i < K - 1; i++) {
			que.push(que.front());
			que.pop();
		}
		std::cout << que.front() << ", ";
		que.pop();
	}
	std::cout << que.front()<<">"<<'\n';
	return 0;
}