#include<iostream>
using namespace std;

void Edit(char Pattern[], char Value[])
{
	char fill = Pattern[0];
	bool signif = false;
	int v = 0;
	for (int p = 0; p < strlen(Pattern); p++) {
		if (Pattern[p] == '$' || Pattern[p] == '?') {
			if (signif == false) {
				if (Pattern[p] == '$' && Value[v] == '0') { ; }
				else if (Value[v + 1] != '+') {
					signif = true;

				}
				if (Value[v] == '0') { Pattern[p] = fill; }
				else { Pattern[p] = Value[v]; }
			}

			else {
				if (Value[v + 1] == '+') { signif = false; }
				Pattern[p] = Value[v];
			}
			v = v + 1;
		}
		else {
			if (signif == false) { Pattern[p] = fill; }
		}
	}
}

int main(void) 
{   
	char Pattern[8 + 1] = "  $$,$$$";
	char Value[6 + 1] = "01234+";
	Edit(Pattern, Value);
	printf("%s\n", Pattern);

	strcpy(Pattern, "*$$,$$$#");
	strcpy(Value, "00000+");
	Edit(Pattern, Value);
	printf("%s\n", Pattern);

	strcpy(Pattern, "*$$$,$$#");
	strcpy(Value, "00012-");
	Edit(Pattern, Value);
	printf("%s\n", Pattern);

	strcpy(Pattern, "*$$?,$$#");
	strcpy(Value,  "00012+");
	Edit(Pattern, Value);
	printf("%s\n", Pattern);
	return 0;
}