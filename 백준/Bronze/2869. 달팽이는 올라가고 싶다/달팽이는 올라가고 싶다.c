#include <stdio.h> 
//#include <string.h>

int main()
{
	int A, B, V, check1, check2, check3, check4;
	scanf("%d %d %d", &A, &B, &V);
	if (V == A) {
		printf("%d", 1);
	}
	else {
		check1 = (V - A);
		check2= (A - B);
		check3 = check1 / check2;
		check4 = check1 % check2;
		if (check1 <= check2)
		{
			printf("%d", 2);
		}
		else if (check4 == 0)
		{
			printf("%d", check3 + 1);
		}
		else 
		{
			printf("%d", check3 + 2);
		}
	}
}