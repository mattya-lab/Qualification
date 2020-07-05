#include<bits/stdc++.h>
using namespace std;

#define N (3 - 1)
#define SOTO_MIGI 97
#define SOTO_SHITA 98
#define SOTO_KADO 99
void print(int houjin[][4]);
void shokika(int houjin[][4]);
void mahoujin(int houjin[][4]);

int main(void) {
	int houjin[4][4];

	shokika(houjin);
	print(houjin);
	mahoujin(houjin);
	print(houjin);
}

void mahoujin(int houjin[][4]) {
	int y = N;
	int x = (N + 1) / 2;
	int suuji = 1;
	houjin[y][x] = 1;

	while (suuji < N * N + 2) {
		int yb = y;
		int xb = x;
		/*
		y = y + 1;
		x = x + 1;

		if (houjin[y][x] == SOTO_SHITA) y = 0;
		else if (houjin[y][x] == SOTO_MIGI) x = 0;
		else if (houjin[y][x] == SOTO_KADO) {
			y = 0;
			x = 0;
		}
		*/
		y = y + 1;
		x = x + 1;
		if (y > N) { y = 0; }
		if (x > N) { x = 0; }

		if (houjin[y][x] != 0) {
			y = yb - 1;
			x = xb;
		}

		suuji = suuji + 1;
		houjin[y][x] = suuji;
	}
}

void shokika(int houjin[][4]) {
	for (int y = 0; y <= N; y++) {
		for (int x = 0; x <= N; x++) {
			houjin[y][x] = 0;
		}
		houjin[y][N + 1] = SOTO_MIGI;
	}
	for (int x = 0; x <= N; x++) {
		houjin[N + 1][x] = SOTO_SHITA;
	}
	houjin[N + 1][N + 1] = SOTO_KADO;
}

void print(int houjin[][4]) {
	printf("--------------------\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d ", houjin[i][j]);
		}
		printf("\n");
	}
}