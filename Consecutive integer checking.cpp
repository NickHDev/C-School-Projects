#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int t = 0;
int m = 0;
int n = 0;
int iterations = 0; 

int gcd(int m, int n, int t)
{
    t = min(m, n);
    while (t > 0)
    {
        iterations++;
        cout << "m: " << m << " n: " << n << "t: " << t << endl;
        if (m % t == 0 && n % t == 0)
        {
            return t;
        }
        t--;
    }
}
int main(){
    printf("Enter two positive integers: ");
    scanf("%d %d", &m, &n);
    printf("GCD(%d, %d) = %d\n", m, n, gcd(m, n, t));
    printf("Number of iterations: %d\n", iterations);
    return 0;
}