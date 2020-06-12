#include<stdio.h>

void swap(int heap[], int i, int j);
void makeHeap(int data[], int heap[], int hnum);
void heapsort(int data[], int heap[], int hnum);
void downheap(int heap[], int hlast);
int lchild(int i) { return 2 * i + 1; }
int rchild(int i) { return 2 * i + 2; }
int parent(int i) { return (i - 1) / 2; }

int main(void)
{
    int hnum = 7;
    int data[7] = { 60, 30, 45, 15,  5, 10, 20 };
    int heap[7] = { 0, 0, 0, 0, 0, 0, 0 };

    printf("------------ Before ------------\n");
    printf("Data: ");
    for (int i = 0; i < hnum; i++) printf("%4d", data[i]);


    printf("\nHeap: ");
    for (int i = 0; i < hnum; i++) printf("%4d", heap[i]);
    printf("\n");
    printf("--------------------------------\n");

    heapsort(data, heap, hnum);

    printf("------------ After -------------\n");
    printf("Data: ");
    for (int i = 0; i < hnum; i++) printf("%4d", data[i]);

    printf("\nHeap: ");
    for (int i = 0; i < hnum; i++) printf("%4d", heap[i]);
    printf("\n");
    printf("--------------------------------\n");
    return 0;
}

void heapsort(int data[], int heap[], int hnum) {
    makeHeap(data, heap, hnum);
    printf("\n%d: Heap: ", 0);
    for (int i = 0; i < hnum; i++) printf("%4d", heap[i]);
    printf("\n");

    for (int last = hnum - 1; last > 0; last--)
    {
	swap(heap, 0, last);
	downheap(heap, last - 1);

	//-----//
	printf("\n%d: Heap: ", hnum - last);
	for (int i = 0; i < hnum; i++) printf("%4d", heap[i]);
	printf("\n");
	//-----//
    }
    printf("\n");
}

void makeHeap(int data[], int heap[], int hnum)
{
    for (int i = 0; i < hnum; i++) {
	heap[i] = data[i];
	int k = i;
	while (k > 0) {
	    if ( heap[k] > heap[parent(k)] /* a */) {
		swap(heap, k, parent(k));  /* b */
		k = parent(k);
	    }
	    else { break; }
	}
    }
}

void downheap(int heap[], int hlast) {
    int n = 0;
    while ( lchild(n) <= hlast ) {
	int tmp = lchild(n);
	if (rchild(n) <= hlast) {
            if (heap[tmp] <= heap[rchild(n)]) {
		tmp = rchild(n);
	    }
	}

	if (heap[tmp] > heap[n]) { swap(heap, n, tmp); }
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
