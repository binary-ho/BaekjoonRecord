#include <stdio.h> 
//#include <string.h>

//int std1, std2;
int N = 0;

int main()
{
	int a, b, c;
	scanf("%d", &a);
	b = a / 10;
	c = a % 10;
	add(b, c, b, c);	
	return 0;
}

int add(int input_1, int input_2, int std1, int std2) {
	int new_num1;
	N++;
	//if (std != (10 * input_1 + input_2))
	// num1은 새로운 1의자리
	new_num1 = (input_1 + input_2) % 10;
	if ((std1 != input_2) || (std2 != new_num1)) {
		add(input_2, new_num1, std1, std2);
	}
	else
	{
		printf("%d", N);
		return N;
	}
}