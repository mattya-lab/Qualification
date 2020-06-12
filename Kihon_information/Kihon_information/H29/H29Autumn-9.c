#include<stdio.h>
#include<ctype.h>

void find_palindrome(const char* text);
int is_palindrome(const char* chars, int size);
const char* find_char(const char* str, char ch);
bool isalnum(char x) { return (('0' <= x && x <= '9' ) || ('a' <= x && 'x' <= 'z') || ('A' <= x && x <= 'Z'))? 1 : 0; }


int main(void) 
{
	find_palindrome("abc0cbe");
	find_palindrome("ABc0CbE");
	find_palindrome("AB!c0 Cb");
	find_palindrome("abc0cb1bc0cbe");
}

void find_palindrome(const char* text)
{
	for (int i = 0; text[i] != '\0'; i++) {
		if (!isalnum(text[i])) { continue; }
		const char* ith = &text[i];
		//printf("%s : %c\n", ith+1, *ith);
		const char* hit = find_char(ith + 1, *ith);
		//printf("%s", hit);

		while (hit != NULL) {
			int psize = hit - ith + 1;
			if (is_palindrome(ith, psize)) {
				while (ith < hit + 1) {
					putchar(*ith);
					ith++;
				}
				putchar('\n');
				return;
			}
			hit = find_char(hit + 1, *ith);
		}
	}
}

int is_palindrome(const char* chars, int size)
{
	int l = 0, r = size - 1;
	while(l < r) {
		while (!isalnum(chars[l])) { l++; }
		while (!isalnum(chars[r])) { r--; }
		if (tolower(chars[l]) != tolower(chars[r])) {
			return 0;
		}
		l++;
		r--;
	}
	return 1;
}

const char *find_char(const char* str, char ch)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (tolower(ch) == tolower(str[i])) {
			return &str[i];
		}
	}
	return NULL;
}
