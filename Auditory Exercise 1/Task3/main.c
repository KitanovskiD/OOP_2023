#include <stdio.h>
#include <math.h>

typedef struct complex_number {
    float real_part;
    float imag_part;
}Complex_Number;

void read_complex_number(Complex_Number *c) {
    scanf("%f %f", &c->real_part, &c->imag_part);
}

void print_complex_number(Complex_Number c) {
    printf("%.2f", c.real_part);
    if (c.imag_part >= 0)
        printf("+j%.2f\n", c.imag_part);
    else
        printf("-j%.2f\n", fabs(c.imag_part));
}

Complex_Number add(Complex_Number c1, Complex_Number c2) {
    Complex_Number result;
    result.real_part = c1.real_part + c2.real_part;
    result.imag_part = c1.imag_part + c2.imag_part;
    return result;
}

Complex_Number diff(Complex_Number c1, Complex_Number c2) {
    Complex_Number result;
    result.real_part = c1.real_part - c2.real_part;
    result.imag_part = c1.imag_part - c2.imag_part;
    return result;
}

Complex_Number multiply(Complex_Number c1, Complex_Number c2) {
    Complex_Number result;
    result.real_part = c1.real_part* c2.real_part - c1.imag_part * c2.imag_part;
    result.imag_part = c1.real_part * c2.imag_part + c1.imag_part * c2.real_part;
    return result;
}

int main() {
    Complex_Number c1;
    Complex_Number c2;

    read_complex_number(&c1);
    read_complex_number(&c2);

    Complex_Number add_result = add(c1, c2);
    Complex_Number diff_result = diff(c1, c2);
    Complex_Number m_result = multiply(c1, c2);

    printf("Results: \n");

    print_complex_number(add_result);
    print_complex_number(diff_result);
    print_complex_number(m_result);

    return 0;
}
