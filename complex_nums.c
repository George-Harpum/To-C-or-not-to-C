#include <stdio.h>

typedef struct complex {
    float real;
    float img;
} complex;


complex comp_add(complex num1, complex num2);
complex comp_sub(complex num1, complex num2);
complex comp_multi(complex num1, complex num2);
complex comp_div(complex num1, complex num2);
void printComplex(complex num);


int main() {
    complex a = {2, 3};
    complex b = {4, 5};
    
    return 0;
} 

complex comp_add(complex num1, complex num2) {
    complex out;
    out.real = num1.real + num2.real;
    out.img = num1.img + num2.img;
    return out;
}

complex comp_sub(complex num1, complex num2) {
    complex out;
    out.real = num1.real - num2.real;
    out.img = num1.img - num2.img;
    return out;
}

complex comp_multi(complex num1, complex num2) {
    complex out;
    out.real = num1.real * num2.real;
    out.real -= num1.img * num2.img;
    out.img = (num1.real * num2.img) + (num1.img * num2.real);
    return out;
}

complex comp_div(complex num1, complex num2) {
    complex out;
    denum = (num2.real * num2.real) + (num2.img * num2.img);
    out.real = (num1.real * num2.real) + (num1.img * num2.img);
    out.real /= denum;
    out.img = (num1.img * num2.real) - (num1.real * num2.img);
    return out; 
}

void printComplex(complex num) {
    printf("(%f+%fi)", num.real, num.img);
}
