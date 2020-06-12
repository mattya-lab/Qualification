#include<stdio.h>
#define INF 99

void print(int pDist[], int pRoute[], bool pFixed[]);

void ShortestPath(int Distance[][7], int nPoint, int sp, int dp, int sRoute[], int *sDist)
{
	int pDist[7], pRoute[7] = {};
	bool pFixed[7];
	*(sDist) = INF;
	
	for (int i = 0; i < nPoint; i++) {
		sRoute[i] = -1;
		pDist[i] = INF;
		pRoute[i] = 0;
		pFixed[i] = false;
	}

	pDist[sp] = 0;
	int cnt = 0;
	while (true) 
	{
		int i = 0;
		//printf("Loop: %d\n", cnt + 1); cnt++;
		//print(pDist, pRoute, pFixed);

		while (i < nPoint) {
			if (!pFixed[i]) { break; }
			i = i + 1;
		}
		if (i == nPoint) { break; }
		for (int j = i + 1; j < nPoint; j++) {
			if (!pFixed[j] && pDist[j] < pDist[i]) { i = j; }
		}
		int sPoint = i;
		pFixed[sPoint] = true;
		for (int j = 0; j < nPoint; j++) {
			if (Distance[sPoint][j] > 0 && !pFixed[j]) {
				int newDist = pDist[sPoint] + Distance[sPoint][j];
				if (newDist < pDist[j]) {
					pDist[j] = newDist;
					pRoute[j] = sPoint;
				}
			}
		}
	}
	*(sDist) = pDist[dp];
	int j = 0;
	int i = dp;
	while (i != sp) {
		sRoute[j] = i;
		i = pRoute[i];
		j = j + 1;
	}
	sRoute[j] = sp;
}

int main(void)
{
	int Distance[7][7] = { 
	    {  0,  2,  8,  4, -1, -1, -1},
	    {  2,  0, -1, -1,  3, -1, -1},
   	    {  8, -1,  0, -1,  2,  3, -1},
	    {  4, -1, -1,  0, -1,  8, -1},
	    { -1,  3,  2, -1,  0, -1,  9},
	    { -1, -1,  3,  8, -1,  0,  3},
	    { -1, -1, -1, -1,  9,  3,  0}
	};

	int sRoute[7];
	int sDist = 0;;
	ShortestPath(Distance, 7, 0, 6, sRoute, &sDist);
	printf("sRoute: ",  sRoute[6]);
	for (int i = 7 - 1 - 1 ; i >= 0; i--) { printf(" -> %d ", sRoute[i]); }
	printf("\nsDist: %2d", sDist);

	return 0;
}

void print(int pDist[], int pRoute[], bool pFixed[])
{
	printf("----------------------------------\n");
	printf("pDist : ");
	for (int i = 0; i < 7; i++) { printf("%2d ", pDist[i]); }
	printf("\n");
	printf("pRoute: ");
	for (int i = 0; i < 7; i++) { printf("%2d ", pRoute[i]); }
	printf("\n");
	printf("pFixed: ");
	for (int i = 0; i < 7; i++) { printf("%2d ", pFixed[i]); }
	printf("\n");
	printf("----------------------------------\n");
}