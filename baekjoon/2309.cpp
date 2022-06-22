// https://www.acmicpc.net/problem/2309

#include <iostream>
#include <algorithm>
#define NSIZE 9

void solution1() 
{
	int arr[NSIZE];
	int ret[NSIZE - 2];
	bool found = false;
	int sum = 0;
	int retcnt = 0;

	for (int i = 0; i < NSIZE; i++)
		std::cin >> arr[i];
	
	for (int i = 0; i < NSIZE; i++) {
		for (int j = i + 1; j < NSIZE; j++) {
			sum = 0;
			retcnt = 0;
			for (int k = 0; k < NSIZE; k++) {
				if (k == i || k == j)
					continue;
				sum += arr[k];
				ret[retcnt++] = arr[k];
			}
			if (sum == 100) {
				found = true;
				break;
			}
		}
		if (found)
			break;
	}

	std::sort(ret, ret + NSIZE - 2);
	for (int i = 0; i < NSIZE - 2; i++)
		std::cout << ret[i] << std::endl;
}

void solution2()
{
	int arr[NSIZE];
	int sum = 0;

	for (int i = 0; i < NSIZE; i++)
		std::cin >> arr[i];
	std::sort(arr, arr + NSIZE);

	do {
		sum = 0;
		for (int i = 0; i < NSIZE - 2; i++) sum += arr[i];
		if (sum == 100) break;
	} while (std::next_permutation(arr, arr + NSIZE));

	for (int i = 0; i < NSIZE - 2; i++)
		std::cout << arr[i] << std::endl;
}

int main(void)
{
	//solution1(); // O(N^2)
	solution2(); // using next_permutation
	return 0;
}
