#include <iostream>
#include "BigInt.h"
//Driver code with some examples
void divide_by_two(BigInt & a){
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0;i--){
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while(a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}



BigInt sqrt(BigInt & a){
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_two(right);
    while(left <= right){
        mid += left;
        mid += right;
        divide_by_two(mid);
        prod = (mid * mid);
        if(prod <= a){
            v = mid;
            ++mid;
            left = mid;
        }
        else{
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}

BigInt NthCatalan(int n){
    BigInt a(1),b;
    for (int i = 2; i <= n;i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n;i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}

BigInt NthFibonacci(int n){
    BigInt a(1), b(1), c;
    if(!n)
        return c;
    n--;
    while(n--){
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}

BigInt Factorial(int n){
    BigInt f(1);
    for (int i = 2; i <= n;i++)
        f *= i;
    return f;
}

int main()
{
    BigInt first("12345");
    cout << "The number of digits"
         << " in first big integer = "
         << Length(first) << '\n';
    BigInt second(12345);
    if (first == second) {
        cout << "first and second are equal!\n";
    }
    else
        cout << "Not equal!\n";
    BigInt third("10000");
    BigInt fourth("100000");
    if (third < fourth) {
        cout << "third is smaller than fourth!\n";
    }
    BigInt fifth("10000000");
    if (fifth > fourth) {
        cout << "fifth is larger than fourth!\n";
    }

    // Printing all the numbers
    cout << "first = " << first << '\n';
    cout << "second = " << second << '\n';
    cout << "third = " << third << '\n';
    cout << "fourth = " << fourth<< '\n';
    cout << "fifth = " << fifth<< '\n';

    // Incrementing the value of first
    first++;
    cout << "After incrementing the"
         << " value of first is : ";
    cout << first << '\n';
    BigInt sum;
    sum = (fourth + fifth);
    cout << "Sum of fourth and fifth = "
         << sum << '\n';
    BigInt product;
    product = second * third;
    cout << "Product of second and third = "
         << product << '\n';

    // Print the fibonacci number from 1 to 100
    cout << "-------------------------Fibonacci"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        BigInt Fib;
        Fib = NthFibonacci(i);
        cout << "Fibonacci " << i << " = " << Fib<<'\n';
    }
    cout << "-------------------------Catalan"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        BigInt Cat;
        Cat = NthCatalan(i);
        cout << "Catalan " << i << " = " << Cat<<'\n';
    }

    // Calculating factorial of from 1 to 100
    cout << "-------------------------Factorial"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        BigInt fact;
        fact = Factorial(i);
        cout << "Factorial of "
             << i << " = ";
        cout << fact << '\n';
    }
}