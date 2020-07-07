#include<stdio.h>
#define rep(i, n) for(int i = 0; i < n; i++ )

#define N 3
#define M 4

int m = M, n = N;
int dv[8], dh[8];
int board[M][N];
bool printflag = 0;

void printBoard()
{
	printf("----------------------------------------\n");
	rep(v, m) {
		rep(h, n) {
			printf("%2d ", board[v][h]);
		}
		printf("\n");
	}
}

void search(int i, int v, int h) {
	if (0 <= v && v <= m - 1) {
		if (0 <= h && h <= n - 1) {
			if (board[v][h] == 0) {
				board[v][h] = i;
				if (i == m * n) {
					printBoard();
					printflag = 1;
				}
				else {
					for (int j = 0; j < 8; j++) {
						search(i + 1, v + dv[j], h + dh[j]);
					}
				}
				board[v][h] = 0;
			}
		}
	}
}

int main(void)
{
	rep(i, M) { rep(j, N) { board[i][j] = 0; } }

	dv[0] = -2; dv[1] = -1; dv[2] = 1; dv[3] = 2;
	dv[4] = 2; dv[5] = 1; dv[6] = -1; dv[7] = -2;

	dh[0] = 1; dh[1] = 2; dh[2] = 2; dh[3] = 1;
	dh[4] = -1; dh[5] = -2; dh[6] = -2; dh[7] = -1;

	search(1, 0, 0);
	if (printflag == 0) { printf("Not Answer\n"); }
	return 0;
}
