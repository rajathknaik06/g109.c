/*Anu wants to develop a program to check whether a number can be expressed as the sum of two prime numbers using recursion. 



Given a positive integer N, write a program for her to check if the number N can be represented as the sum of two prime numbers.



Function Specifications: int sum_of_two_primes(int)

Input format :
The input consists of an integer N.

Output format :
The output prints all possibilities of N, which can be represented as the sum of two prime numbers.

If there is no possibility, print "[N] cannot be expressed as the sum of two prime numbers"*/

#include <stdio.h>

int is_prime(int n, int i);
int sum_of_two_primes(int n);

int main() {
    int n;
    scanf("%d", &n);
    int flag = 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (sum_of_two_primes(i) && sum_of_two_primes(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("%d cannot be expressed as the sum of two prime numbers", n);
    return 0;
}

int is_prime(int n, int i) {
    if (i == 1)
        return 1;
    if (n % i == 0)
        return 0;
    return is_prime(n, i - 1);
}

int sum_of_two_primes(int n) {
    if (n <= 1)
        return 0;
    return is_prime(n, n / 2);
}


//solution 2

#include <iostream>
using namespace std;

bool is_prime(int n, int i);
bool sum_of_two_primes(int n);

int main() {
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 2; i <= n / 2; ++i) {
        if (sum_of_two_primes(i) && sum_of_two_primes(n - i)) {
            cout << n << " = " << i << " + " << (n - i) << endl;
            flag = true;
        }
    }
    if (!flag)
        cout << n << " cannot be expressed as the sum of two prime numbers" ;
    return 0;
}

bool is_prime(int n, int i) {
    if (i == 1)
        return true;
    if (n % i == 0)
        return false;
    return is_prime(n, i - 1);
}

bool sum_of_two_primes(int n) {
    if (n <= 1)
        return false;
    return is_prime(n, n / 2);
}

