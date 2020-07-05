#include<bits/stdc++.h>
using namespace std;

#define N 4

void print(int m[]);
void copy(int arr1[], int arr2[]);
void clear(int arr[]);
void update(int m[]);

bool shouldBe(int m[], int p, int r[]) {
	for (int i = 1; i <= p - 1; i++) {
		update(m);
	}
	for (int i = 1; i <= N * N; i++) {
		if (m[i] != r[i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int m[N * N + 1];
	m[0] = -1;

	m[1] = 0;  m[2] = 1; m[3] = 0; m[4] = 0;
	m[5] = 0;  m[6] = 0; m[7] = 1; m[8] = 0;
	m[9] = 1;  m[10] = 1; m[11] = 1; m[12] = 0;
	m[13] = 0; m[14] = 0; m[15] = 0; m[16] = 0;

	print(m);
	//update(m);
	//print(m);
	//update(m);
	//print(m);

	int r[N * N + 1];
	r[0] = -1;

	r[1] = 0;  r[2] = 0; r[3] = 0; r[4] = 0;
	r[5] = 0;  r[6] = 0; r[7] = 1; r[8] = 0;
	r[9] = 1;  r[10] = 0; r[11] = 1; r[12] = 0;
	r[13] = 0; r[14] = 1; r[15] = 1; r[16] = 0;

	if (shouldBe(m, 3, r)) printf("True\n");
	else printf("False\n");
	return 0;
}

void update(int m[]) {
	int temp[N * N + 1];
	copy(m, temp);
	clear(m);
	for (int i = 1; i < N * N; i++) {
		int a, b, c;

		if ((i - 1) % N == 0) {
			a = 0;
			b = 1;
		}
		else if(i % (N) == 0) { 
			a = -1;
			b = 0;
		}
		else {
			a = -1;
			b = 1;
		}
		int e = 0;
		for (int y = -1; y <= 1; y++) {
			for (int x = a; x <= b; x++) {
				if (y != 0 || x != 0) {
					c = i + y * (N) + x;
					if (1 <= c && c <= N * N - 1) {
						if (temp[c] == 1) {
							e = e + 1;
							//cout << c << " " << e << endl;
						}
					}
				}
			}
		}
		if (temp[i] == 0 && e == 3) { m[i] = 1; }
		else if (temp[i] == 1 && (e == 2 || e == 3)) { m[i] = 1; }
	}
}

void copy(int arr1[], int arr2[]) {
	for (int i = 1; i <= N * N; i++) {
		arr2[i] = arr1[i];
	}
}

void clear(int arr[])
{
	for (int i = 1; i <= N * N; i++) {
		arr[i] = 0;
	}
}

void print(int m[]) {
	printf("-------------------------------\n");
	for (int k = 0; k < N; k++) {
		for (int j = 1; j <= N; j++) {
			printf("%2d", m[k * N + j]);
		}
		printf("\n");
	}
}