#include<iostream>
#include<stdio.h>
#include<string.h>


char IntToAlphabet(int x);
int AlphabetToInt(char x);

void Compress(char Plaindata[], int Plength, char Compresseddata[], int Clength);
void Decompress(char Compresseddata[], int Clength, char Plaindata[], int Plength);


int main(void) 
{	
	char Plaindata[16 + 1] = "ABCDEFABCDABCDEF";
	char Compresseddata[31 + 1] = ""; 
	cout << Plaindata << endl;

	Compress(Plaindata, strlen(Plaindata), Compresseddata, 0);
	cout << Compresseddata << endl;

	Decompress(Compresseddata, strlen(Compresseddata), Plaindata, 0);
	cout << Plaindata << endl;

	return 0;
}

char IntToAlphabet(int x) {
	char str[26 + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return str[(x - 1) % 26];
}

int AlphabetToInt(char x) {
	return x - 'A';
}
void Decompress(char Compresseddata[], int Clength, char Plaindata[], int Plength)
{
	if (Clength >= 1) {
		char Esym = '$';
		int Cindex = 0;
		int Pindex = 0;
		while (Cindex < Clength) {
			if (Compresseddata[Cindex] != Esym) {
				Plaindata[Pindex] = Compresseddata[Cindex];
				Pindex = Pindex + 1;
				Cindex = Cindex + 1;
			}
			else {
				int Num = AlphabetToInt(Compresseddata[Cindex + 2]);
				int Start = AlphabetToInt(Compresseddata[Cindex + 1]);
				for (int Fitcnt = 0; Fitcnt < Num; Fitcnt++) {
					Plaindata[Pindex + Fitcnt] = Plaindata[Pindex - Start + Fitcnt];
				}
				Pindex = Pindex + Num;
				Cindex = Cindex + 3;
			}
		}
		Plength = Pindex;
	}
}

void Compress(char Plaindata[], int Plength, char Compresseddata[], int Clength)
{
	if (Plength >= 1) {
		char Esym = '$';
		int Pindex = 0;
		int Cindex = 0;
		while (Pindex < Plength && Pindex < 4) {
			Compresseddata[Cindex] = Plaindata[Pindex];
			Cindex = Cindex + 1;
			Pindex = Pindex + 1;
		}
		while (Pindex < Plength) {
			int Maxfitnum = -1;
			int Maxdistance = -1;
			int Distance = 4;
			while (Distance <= 26 && Pindex - Distance >= 0) {
				int Fitnum = 0;
				while (Fitnum < Distance and (Pindex + Fitnum) < Plength) {
					if (Plaindata[Pindex + Fitnum] != Plaindata[Pindex - Distance + Fitnum]) break;
					Fitnum = Fitnum + 1;
				}
				if (Fitnum >= 4 && Maxfitnum < Fitnum) {
					Maxfitnum = Fitnum;
					Maxdistance = Distance;
				}
				Distance = Distance + 1;;
			}
			if (Maxfitnum == -1) {
				Compresseddata[Cindex] = Plaindata[Pindex];
				Cindex = Cindex + 1;
				Pindex = Pindex + 1;
			}
			else {
				Compresseddata[Cindex] = Esym;
				Compresseddata[Cindex + 1] = IntToAlphabet(Maxdistance);
				Compresseddata[Cindex + 2] = IntToAlphabet(Maxfitnum);
				Cindex = Cindex + 3;
				Pindex = Pindex + Maxfitnum;
			}
		}
		Clength = Cindex;
	}
}