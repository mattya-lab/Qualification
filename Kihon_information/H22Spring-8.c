#include<stdio.h>

void merge(int slist1[], int num1, int slist2[], int num2, int list[]);
void sort(int list[], int num);

void print(int list[]) {
	for (int i = 0; i < 7; i++) printf("%2d", list[i]);
	printf("\n");
}

int main() {
	int list[7] = { 5, 7, 4, 2, 3, 8, 1 };
	print(list);
	sort(list, 7);
	print(list);
	return 0;
}

void merge(int slist1[], int num1, int slist2[], int num2, int list[]) {
	int i = 0, j = 0;
	while ((i < num1) && (j < num2)) {
		if (slist1[i] < slist2[j]) {
			list[i + j] = slist1[i];
			i = i + 1;
		}
		else {
			list[i + j] = slist2[j];
			j = j + 1;
		}
	}
	while ((i < num1) || (j < num2)) {
		if (i < num1) {
			list[i + j] = slist1[i];
			i = i + 1;
		}
		else {
			list[i + j] = slist2[j];
			j = j + 1;
		}
	}
}

void sort(int list[], int num)
{

	int slist1[7], slist2[7];

	if (num > 1) {
		int num1 = num / 2;
		int num2 = num - num1;

		for (int i = 0; i < num1; i++) {
			slist1[i] = list[i]; 
		}
		for (int i = 0; i < num2; i++) {
			slist2[i] = list[num1 + i]; 
		}

		sort(slist1, num1);
		sort(slist2, num2);
		merge(slist1, num1, slist2, num2, list);
	}
}