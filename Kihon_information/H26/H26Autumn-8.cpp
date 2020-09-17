#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

int calcEditDistance(const char *Str1, int Str1Len, const char *Str2, int Str2Len) {
	vvi D(Str1Len + 1, vi(Str2Len + 1));

	for (int x = 0; x <= Str1Len; x++) { D[x][0] = x; }
	for (int y = 0; y <= Str2Len; y++) { D[0][y] = y; }

	for (int x = 1; x <= Str1Len; x++) {
		for (int y = 1; y <= Str2Len; y++) {
			if (Str1[x - 1] == Str2[y - 1]) {
				D[x][y] = min(D[x - 1][y - 1], min(D[x][y - 1] + 1, D[x - 1][y] + 1));
			}
			else {
				D[x][y] = min(D[x][y - 1] + 1, D[x - 1][y] + 1);
			}
		}
	}

	for (int x = 0; x <= Str1Len; x++) {
		for (int y = 0; y <= Str2Len; y++) {
			cout << D[x][y] << " ";
		}
		cout << endl;
	}
	return (D[Str1Len][Str2Len]);
}

int main(void) {
	printf("Distance: %d\n", calcEditDistance("abcabba", 7, "cbabac", 6));
	printf("Distance: %d\n", calcEditDistance("peace", 5, "people", 6));
	return 0;
}