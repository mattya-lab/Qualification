#include<iostream>
using namespace std;

int MemoCnt = 0, MemoMax = 5, Memo[5];
int DataLen = 0, DataMax = 5;
char Data[25];

void print();
void reset() { MemoCnt = 0; DataLen = 0; }
void addMemo(int textLen, const char* text);
void deleteMemo(int pos);
void changeMemo(int pos, int textLen, const char* text);
void moveMemo(int fromPos, int toPos);

void clearGarbage()
{
	char temp[25] = "";

	DataLen = 0;
	if (MemoCnt == 0) { return; }
	for (int m = 0; m < MemoCnt; m++) {
		int d = Memo[m];
		Memo[m] = DataLen;
		for (int i = 0; i <= Data[d] - '0'; i++) {
			temp[DataLen] = Data[d + i];
			DataLen = DataLen + 1;
		}
	}
	for (int d = 0; d < DataLen; d++) {
		Data[d] = temp[d];
	}
}

int main(void)
{
	addMemo(4, "Aoki");
	addMemo(4, "Imai");
	addMemo(3, "Uno");
	addMemo(4, "Endo");
	printf("addMemo\n");  print();

	deleteMemo(0);
	printf("deleteMemo\n");  print();
	changeMemo(2, 3, "Abe");
	printf("changeMemoMemo\n");  print();
	moveMemo(2, 0);
	printf("moveMemo\n");  print();
	clearGarbage();
	printf("clearGarbage\n");  print();
	reset();
	printf("reset\n");  print();
	return 0;
}


void addMemo(int textLen, const char* text)
{
	Memo[MemoCnt] = DataLen;
	MemoCnt = MemoCnt + 1;
	Data[DataLen] = textLen + '0';
	DataLen = DataLen + 1;
	for (int i = 0; i < textLen; i++) {
		Data[DataLen + i] = text[i];
	}
	DataLen = DataLen + textLen;
}

void deleteMemo(int pos) {
	for (int i = pos + 1; i < MemoCnt; i++) { Memo[i - 1] = Memo[i]; }
	Memo[MemoCnt - 1] = 0;
	MemoCnt = MemoCnt - 1;
}

void moveMemo(int fromPos, int toPos)
{
	int m = Memo[fromPos];
	if (fromPos < toPos) {
		for (int i = fromPos; i <= toPos - 1; i++) { Memo[i] = Memo[i + 1]; }
	}
	if (fromPos > toPos) {
		for (int i = fromPos; i >= toPos + 1; i--) { Memo[i] = Memo[i - 1]; }
	}
	Memo[toPos] = m;
}

void changeMemo(int pos, int textLen, const char* text)
{
	Memo[pos] = DataLen;
	Data[DataLen] = textLen + '0';
	DataLen = DataLen + 1;
	for (int i = 0; i < textLen; i++) { Data[DataLen + i] = text[i]; }
	DataLen = DataLen + textLen;
}

void print()
{
	printf("----------------------------------\n");
	printf("Memo : ");
	for (int i = 0; i < MemoMax; i++) { printf("%2d ", Memo[i]); };
	printf(", MemoCnt :%d", MemoCnt);
	printf(", DataLen :%d", DataLen);
	printf("\n");
	printf("Data: ");
	for (int i = 0; i < strlen(Data); i++) printf("%c ", Data[i]);
	printf("\n");
	printf("----------------------------------\n");
}