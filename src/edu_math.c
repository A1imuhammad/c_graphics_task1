#include "edu_math.h"

#include <stdio.h>
#include <stdlib.h>

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

int edu_add(int a, int b) {
    return a + b;
}

int edu_sub(int a, int b) {
    return a - b;
}


int edu_mult(int a, int b) {
    return a * b;
}

int edu_div(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "[ERROR] division by zero\n");
    }
    return a / b;
}

int edu_mod(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "[ERROR] modulo by zero\n");    
    }
    return a % b;
}
int edu_pow(int a, int b) {
    if (b < 0) {
        fprintf(stderr, "[ERROR] negative exponent not supported\n");
    }
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int edu_abs(int a) {
    return (a < 0) ? -a : a;
}

int edu_gcd(int a, int b) {
    a = edu_abs(a);
    b = edu_abs(b);
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int edu_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return edu_abs(a * b) / edu_gcd(a, b);
}

int edu_int_sqrt(int a) {
    if (a < 0) {
        fprintf(stderr, "[ERROR] sqrt of negative number\n");
    }
    int x = 0;
    while ((x + 1) * (x + 1) <= a) {
        x++;
    }
    return x;
}

int edu_sgn(int a) {
    if (a > 0) return 1;
    if (a < 0) return -1;
    return 0;
}

int edu_fact(int a) {
    if (a < 0) {
        fprintf(stderr, "[ERROR] factorial of negative number\n");
        
    }
    int result = 1;
    for (int i = 2; i <= a; i++) {
        result *= i;
    }
    return result;
}