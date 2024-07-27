#include <stdio.h>
#include <stdlib.h>

void matrix_vector_product(float *A, float *v_in, float *v_out, int n)
{
    for (int i = 0; i < n; i++){
        float sum = 0.0f;
        for (int j = 0; j < n; j++) {
            sum += A[i * n + j] * v_in[j];
        }
        v_out[i] = sum;
    }
}



int main(int argc, char **argv){

    float *A, *v_in, *v_out;

    int n = 3;
    
    A =  (float *) malloc(n * n * sizeof(float));
    v_in = (float *) malloc(n * sizeof(float));
    v_out = (float *) malloc(n *  sizeof(float));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i * n + j] = (float) i * n + j;

        }
    }

    for (int i = 0; i < n; i++) {
        v_in[i] = (float) i;
    }

    matrix_vector_product(A, v_in, v_out, n);

    for (int i = 0; i < n; i++) {
        printf("%.2f\n", v_out[i]);
    }

    free(A);
    free(v_in);
    free(v_out);


    return 0;
}