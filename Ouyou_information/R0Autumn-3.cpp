#include<stdio.h>

void simple_perceptron(int ni, int nc, int x[][2], int y[], double wy[], double by);

void three_layer_perceptron(int ni, int nm, int nc, int x[][2],int m[][2], int y[], 
	                        double wm[][2], double wy[], double bm[], double by) {
	for (int out = 0; out < nc; out++) {
		double ytemp = by;
		for (int mid = 0; mid < nm; mid++) {
			double mtemp = bm[mid];
			for (int in = 0; in < ni; in++) {
				mtemp = mtemp + x[out][in] * wm[mid][in];
			}
			if (mtemp > 0.0) { m[out][mid] = 1; }
			else{ m[out][mid] = 0; }

			ytemp = ytemp + m[out][mid] * wy[mid];
			if (ytemp > 0.0) { y[out] = 1; }
			else { y[out] = 0; }
		}
	}
}

int main(void) 
{
	int ni = 2;
	int nc = 4;

	int x[4][2] = {
		{0, 0},
		{0, 1},
		{1, 0},
		{1, 1}
	};

	int y[4] = {0, 0, 0, 0};
	double wy[2] = { 0.5, 0.5 };
	double by = (-1.0) * 0.2;

	simple_perceptron(ni, nc, x, y, wy, by);
	printf("%d %d %d %d\n", y[0], y[1], y[2], y[3]);

	int nm = 2;
	int m[2][2] = { 
		{0, 0}, 
		{0, 0,}
	};
	double wm[2][2] = {
		{0.5, 0.5},
		{-0.5, -0.5}
	};
	double bm[2] = { -0.2, 0.7 };
	by = -0.7;
	three_layer_perceptron(ni, nm, nc, x, m, y, wm, wy, bm, by);

	printf("%d %d %d %d\n", y[0], y[1], y[2], y[3]);

	return 0;
}

void simple_perceptron(int ni, int nc, int x[][2], int y[], double wy[], double by) {
	for (int out = 0; out < nc; out++) {
		double ytemp = by;
	
		for (int in = 0; in < ni; in++) {
			ytemp = ytemp + (double)x[out][in] * wy[in];
		}
	
		if (ytemp > 0.0) { y[out] = 1; }
		else { y[out] = 0; }
	}
}