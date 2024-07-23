#include <stdio.h>
#include <stdlib.h>

void matrix_matrix_product(float *A, float *B, float *C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A[i * n + k] * B[k * n + j];
            }
            C[i * n + j] = sum;
        }
    }
}


int main(int argc, char **argv){

    float *A, *B, *C;

    int n = 3;

    A =  (float *) malloc(n * n * sizeof(float));
    B =  (float *) malloc(n * n * sizeof(float));
    C =  (float *) malloc(n * n * sizeof(float));


     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i * n + j] = (float) i * n + j;
            B[i * n + j] = (float) i * n + j;
        }
    }

    matrix_matrix_product(A, B, C, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2f\n", C[i * n + j]);
        }
    }

    free(A);
    free(B);
    free(C);

    return 0;
}

