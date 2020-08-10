#include<bits/stdc++.h>
using namespace std;

#define V (5)
#define N (3)

int main(void)
{
	int size[N] = {1, 2, 3};
	int value[N] = {2, 6, 9};
	int maxvalue[V + 1];
	int choice[V + 1];

	for (int k = 0; k <= V; k++) {
		maxvalue[k] = 0;
		choice[k] = -1;
	}

	for(int s = 0; s < N; s++){
		for(int t = size[s]; t <= V; t++){
			int temp = maxvalue[t - size[s]] + value[s];
			if (temp > maxvalue[t]) {
				maxvalue[t] = temp;
				choice[t] = s;
			}
		}
	}
	
	int k = V;
	while (choice[k] >= 0) {
		cout << choice[k] << endl;
		k = k - size[choice[k]];
	}
	cout << maxvalue[V] << endl;

	return 0;
}
