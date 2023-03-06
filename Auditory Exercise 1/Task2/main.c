#include <stdio.h>

typedef struct vector{
    float x;
    float y;
    float z;
}Vector;

void read_vector(Vector *v) {
    scanf("%f %f %f", &v->x, &v->y, &v->z);
}

void print_vector(Vector v) {
    printf("Vector: x=%.2f, y=%.2f, z=%.2f", v.x, v.y, v.z);
}

float scalar_product(Vector v1, Vector v2) {
    return (v1.x*v2.x) + (v1.y*v2.y) + (v1.z*v2.z);
}

Vector vector_product(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;

    return result;
}

int main() {
    Vector v1;
    Vector v2;

    read_vector(&v1);
    read_vector(&v2);


    Vector vector_product_result = vector_product(v1, v2);

    printf("Results:\n");
    printf("Scalar Product: %.2f\n", scalar_product(v1, v2));
    printf("Vector product: ");
    print_vector(vector_product_result);

    return 0;
}
