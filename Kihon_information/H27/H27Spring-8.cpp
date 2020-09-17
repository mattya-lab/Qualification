#include<bits/stdc++.h>
using namespace std;

void print_array(int x[]) {
	printf("x: ");
	for (int i = 1; i < 8; i++) {
		printf("%2d ", x[i]);
	}
	printf("\n");
}

int select(int x[], int n, int k) {
	int top = 1;
	int last = n;
	//int cnt_a = 0, cnt_c = 0;
	while (top < last) {
		int pivot = x[k]; 
		int i = top;
		int j = last;
		//cnt_a = cnt_a + 1;
		//cout << "cnt_a : " << cnt_a << endl;

		while (true) {
			while (x[i] < pivot) i = i + 1;
			//while (x[i] <= pivot) i = i + 1;
			while (pivot < x[j]) j = j - 1;
			if (i >= j) {
				break;
			}
			int work = x[i];
			x[i] = x[j];
			x[j] = work;
			i = i + 1;
			j = j - 1;
			//print_array(x);
			//cnt_c = cnt_c + 1;
			//cout << "cnt_c : " << cnt_c << endl;
		}
		if (i <= k) top = j + 1;
		if (k <= j) last = i - 1;
	}

	return x[k];
}

int main(void)
{
	// int x[8] = { '\0', 3, 5, 6, 4, 7, 2, 1 };
	// cout << "1: " << select(x, 7, 3) << endl;
	// cout << "2: " << select(x, 7, 6) << endl;

	int x[8] = { '\0', 1, 3, 2, 4, 2, 2, 2 };
	select(x, 7, 3);
	/*
	int x[7] = { '\0', 1, 1, 1, 1, 1, 1 };
	select(x, 6, 3);

	int x[7] = { '\0', 1, 3, 2, 4, 2, 2 };
	select(x, 6, 3);
	*/
	return 0;
}
