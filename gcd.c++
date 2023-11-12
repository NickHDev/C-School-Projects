#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int a = 0;
int b = 0;
int gcd(int a, int b){
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int main(){
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("GCD of %d and %d is %d", a, b, gcd(a, b));
    return 0;
}