#include<iostream>
using namespace std;
int Index(char x);
int GenerateBitMask(const char* Pat, int Mask[]);

int  BitapMatch(const char* Text, const char* Pat)
{
	int Mask[26 + 1];
	int TextLen = strlen(Text);
	int PatLen = GenerateBitMask(Pat, Mask);
	int Status = 0b0000000000000000;
	int Goal = (1 >> (PatLen - 1));
	
	for (int i = 0; i < TextLen; i++) {
		printf("%2d, ", i);
		printf("Status: %2d, Mask[Index(Text[i])]): %2d\n", Status, Mask[Index(Text[i])]);
		Status = (Status << 1) | 0b0000000000000001;
		Status = Status & Mask[Index(Text[i])];

		

		if ((Status & Goal) != 0) { return (i + 1 - PatLen + 1); }
	}

	return (-1);
}

int main(void)
{
	cout << BitapMatch("AACBBAACABABAB", "ACABAB") << endl;
	return 0;
}

int GenerateBitMask(const char* Pat, int Mask[])
{
	int PatLen = strlen(Pat);
	for (int i = 0; i < 26; i++) { Mask[i] = 0b0000000000000000; }
	for (int i = 0; i < PatLen; i++) {
		Mask[Index(Pat[i])] = (0b0000000000000001 << ((i + 1) - 1)) | Mask[Index(Pat[i])];
	}
	//for (int i = 0; i < 26; i++) cout << Mask[i] << endl;
	return PatLen;
}

int Index(char x) {
	char str[26 + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 26; i++) {
		if (str[i] == x) {
			return (i);
		}
	}
	return -1;
}