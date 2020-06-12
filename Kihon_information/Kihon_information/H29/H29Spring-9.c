#include<stdio.h>

void marking(int numQ, int type[], unsigned int ansC[], unsigned int ansE[], int mark[]);
int countMarkBits(unsigned int ans);

int main(void) {
	int n = 2;
	int numQ = 1, type[3 + 1] = { n, 0, 0 }, mark[3 + 1] = {};
	unsigned int ansC[3 + 1] = { 0b0100100000000000, 0, 0 }, ansE[3 + 1] = { 0b0101000000000000, 0, 0 };

	marking(numQ, type, ansC, ansE, mark);
	//printf("%d", mark[0]);

	numQ = 3, type[0] = 11, type[1] = 12, type[2] = 13;
	ansC[0] = 0b0100000000000000, ansC[1] = 0b0001000000000000, ansC[2] = 0b0000100000000000;
	ansE[0] = 0b0000100000000000, ansE[1] = 0b0000100000000000, ansE[2] = 0b0101000000000000;
	marking(numQ, type, ansC, ansE, mark);
	for (int i = 0; i < numQ; i++) { printf("mark[%d] : %d\n", i, mark[i]); }

	return 0;
}

void marking(int numQ, int type[], unsigned int ansC[], unsigned int ansE[], int mark[])
{
	unsigned int sumC, sumE;
	for (int i = 0; i < numQ; i++) {
		mark[i] = 0;
		if (type[i] == 1) {
			if (ansE[i] == ansC[i]) {
				mark[i] = 1;
			}
		}
		else if (2 <= type[i] && type[i] <= 8) {
			if (countMarkBits(ansE[i]) <= type[i] + 1) {
				mark[i] = countMarkBits(ansC[i] & ansE[i]);
			}
		}
		else if (11 <= type[i] && type[i] <= 13) {
			if (type[i] == 11) {
				sumC = 0;
				sumE = 0;
			}
			sumC = sumC | ansC[i];
			if (countMarkBits(ansE[i]) == 1) {
				sumE = sumE | ansE[i];
			}
			if (type[i] == 13) {
				mark[i] = countMarkBits(sumC & sumE);
			}

		}
	}
}

int countMarkBits(unsigned int ans)
{
        int count = 0;
	unsigned int work = ans;
	while (work != 0) {
		count++;
		work = work & (work - 1);
	}
	return count;
}