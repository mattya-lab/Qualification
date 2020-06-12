#include<stdio.h>

#define N (255)

void swap(int heap[], int i, int j);
void makeHeap(int data[], int heap[], int hnum, int node[]);
void heapsort(int freq[], int nsize, int node[]);
void downheap(int heap[], int hlast, int node[]);
int lchild(int i) { return 2 * i + 1; }
int rchild(int i) { return 2 * i + 2; }
int parent(int i) { return (i - 1) / 2; }
void Huffman(int size, int parent[], int left[], int right[], int freq[]);
int SortNode(int size, int parent[], int freq[], int nsize, int node[]);
void Encode(int k, int parent[], int left[]);

void Print(int size, int parent[], int left[], int right[], int freq[])
{
	printf("Huffman:  ");
	for (int i = 0; i < size; i++) printf("%d   ", i);
	printf("\nparent: ");
	for (int i = 0; i < size; i++) printf("%3d ", parent[i]);
	printf("\nleft:   ");
	for (int i = 0; i < size; i++) printf("%3d ", left[i]);
	printf("\nright:  ");
	for (int i = 0; i < size; i++) printf("%3d ", right[i]);
	printf("\nfreq:   ");
	for (int i = 0; i < size; i++) printf("%3d ", freq[i]);
	printf("\n");
}

int main(void) 
{ 
	int size = 4;
	char word[4+1] = "ABCD" ;
	char estr[N] = "AAAABBCDCDDACCAAAAA"; // Encode string 
	//char estr[N] = "ABBBBBBBCCCDD";
	printf("Str: %s\n", estr);

	int parent[N], left[N], right[N], freq[N];
	for (int i = 0; i < N; i++) {
		parent[i] = -1;
		left[i] = -1;
		right[i] = -1;
		freq[i] = -1;
	}
	//freq[0] = 10; freq[1] = 2; freq[2] = 4; freq[3] = 3;
	for (int i = 0; i < 4; i++) {
		freq[i] = 0;
		for (int j = 0; j < strlen(estr); j++) {
			if ( (word[i] ==  estr[j]) ) freq[i] = freq[i] + 1;
		}
	}
	
	Huffman(size, parent, left, right, freq);
	
	printf("Encode: ");
	for (int i = 0; i < strlen(estr); i++) {
		if (estr[i] == 'A') { Encode(0, parent, left); }
		else if (estr[i] == 'B') { Encode(1, parent, left); }
		else if (estr[i] == 'C') { Encode(2, parent, left); }
		else { Encode(3, parent, left); }
		printf(" ");
	}
	printf("\n");
	return 0;
}

void Encode(int k, int parent[], int left[]) {
	if (parent[k] >= 0) {
		Encode(parent[k], parent, left);
		if ( left[parent[k]] == k ) { printf("0"); }
		else { printf("1"); }
	}
}

void Huffman(int size, int parent[], int left[], int right[], int freq[]) {
	int nsize = 0;
	int node[N];
	nsize = SortNode(size, parent, freq, nsize, node);
	//Print(size, parent, left, right, freq);
	
	while(nsize >= 2) 
	{
		/*
		printf("-----------------------\n");
		for (int i = 0; i < nsize; i++)
			printf("node[%d]: %d, freq[%d]: %d\n", i, node[i], i, freq[node[i]]);
		printf("-----------------------\n");
		*/
		int i = node[0];
		int j = node[1];
		left[size] = i;
		right[size] = j;
		freq[size] = freq[i] + freq[j];
		parent[i] = size;			
		parent[j] = size;
		size = size + 1;
		nsize = SortNode(size, parent, freq, nsize, node);
		//Print(size, parent, left, right, freq);
	}
}

int SortNode(int size, int parent[], int freq[], int nsize, int node[]) {
	nsize = 0;
	for (int i = 0; i < size; i++) {
		if (parent[i] < 0) {
			node[nsize] = i;
			nsize = nsize + 1;
		}
	}
	
	heapsort(freq, nsize, node);

	return nsize;
}

void heapsort(int freq[], int nsize, int node[])
{
	int data[N];
	int hnum = nsize;

	makeHeap(freq, data, hnum, node);
	for (int last = hnum - 1; last > 0; last--)
	{
		swap(data, 0, last);
		swap(node, 0, last);     
		downheap(data, last - 1, node); 
	}
   
}

void makeHeap(int data[], int heap[], int hnum, int node[])
{
	for (int i = 0; i < hnum; i++) {
		heap[i] = data[node[i]];
		int k = i;
		while (k > 0) {
			if (heap[k] > heap[parent(k)]) {
				swap(heap, k, parent(k));
				swap(node, k, parent(k));
				k = parent(k);
			}
			else { break; }
		}
	}
}

void downheap(int heap[], int hlast, int node[]) 
{
	int n = 0;
	while (lchild(n) <= hlast) {
		int tmp = lchild(n);
		if (rchild(n) <= hlast) {
			if (heap[tmp] <= heap[rchild(n)]) {
				tmp = rchild(n);
			}
		}

		if (heap[tmp] > heap[n]) { 
			swap(heap, n, tmp); 
			swap(node, n, tmp);
		}
		else { return; }

		n = tmp;
	}
}

void swap(int heap[], int i, int j) 
{
	int tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
}