#include<stdio.h>
/*
int pat[2][2] = {{ 1, 1},
                 { 1, 0} };
*/
int pat[2][3] = { { 1, 1, 1},
                  { 1, 0, 1} };
int p_rn = sizeof(pat) / sizeof(pat[0]);
int p_cn = sizeof(pat[0]) / sizeof(pat[0][0]);

void print_frac(int d);
int exists_at(int i, int j , int d);

int main(void) 
{
    print_frac(3);
}
int exists_at(int i, int j, int d)
{
    if (d == 0) { return 1; }
    else if (exists_at(i / p_rn, j / p_cn, d - 1) == 0) { return 0; }
    else { return pat[i % p_rn][j %p_cn]; }
}

void print_frac(int d) 
{
    int rn = 1, cn = 1;
    for (int i = 0; i < d; i++) {
        rn *= p_rn;
        cn *= p_cn;
    }
    for (int i = 0; i < rn; i++) {
        for (int j = 0; j < cn; j++) {
            putchar(exists_at(i, j, d) ? '*' : ' ');
        }
        putchar('\n');
    }
}