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


int gcd(int m, int n)
{
    while (n != 0)
    {
        iterations++;
        t = m % n;
        m = n;
        n = t;
        cout << "m: " << m << " n: " << n << "t: " << t << endl;   
    }
    return m;
}

int main(){
    printf("Enter two positive integers: ");
    cin >> m >> n;
    printf("GCD(%d, %d) = %d\n", m, n, gcd(m, n));
    printf("Number of iterations: %d\n", iterations);
    return 0;
}
