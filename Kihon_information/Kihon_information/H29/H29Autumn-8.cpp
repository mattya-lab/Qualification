#include<iostream>
#include<string.h>

int n = 30;
const char str[30+1] = " ,,?abcdefghijklmnopqrstuvwxyz";


int getValue(char x) { for (int i = 0; i < n; i++) { if (str[i] == x) return (i); } }
char getChar(int check_value) { return str[check_value]; }

char calcCheckCharacter(const char* input, int len);
bool validateCheckCharacter(const char* input, int len);

int main(void)
{
	char input[6 + 1] = "ipa  ";
	input[5] = calcCheckCharacter(input, 5);
	cout << input << endl;

	if (validateCheckCharacter("ipb  f", 6)) cout << "yes" << endl;
	else cout << "no" << endl;
	
	if (validateCheckCharacter("api  f", 6)) cout << "yes" << endl;
	else cout << "no" << endl; 

	if (validateCheckCharacter("pia  f", 6)) cout << "yes" << endl;
	else cout << "no" << endl;

	if (validateCheckCharacter("  apif", 6)) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}

char calcCheckCharacter(const char* input, int len)
{
	int sum = 0;
	bool is_even = false;
	for (int i = len - 1; i >= 0; i--) {
		cout << input[i] << endl;
		int value = getValue(input[i]);
		if (is_even) { sum = sum + value; }
		else { sum = sum + (value * 2) / n + (value * 2) % n; }
		is_even = !(is_even);
	}
	int check_value = (n - sum % n) % n;
	return getChar(check_value);
}

bool validateCheckCharacter(const char* input, int len)
{
	int sum = 0;
	bool is_odd = true;
	bool ret_value = true;
	for (int i = len - 1; i >= 0; i--) {
		int value = getValue(input[i]);
		if (is_odd) sum = sum + value;
		else { sum = sum + (value * 2) / n + (value * 2) % n; }
		is_odd = !(is_odd);
	}

	if (sum % n != 0) { ret_value = false; }
	return ret_value;
}