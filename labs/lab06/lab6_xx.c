// lab6_xx.c
// Your Name Email Date

#include <stdlib.h> // for malloc

// Add two m x n matrices and get an m x n sum: Y = A + B
void add(int m, int n, double *A, double *B, double *Y) {

}

// Y = sa * A + sb * B
void linearcomb(int m, int n, double sa, double sb, double *A, double *B,
                double *Y) {

}

// At = transpose(A). A is an m x n matrix, so At is an n x m matrix
void transpose(int m, int n, double *A, double *A_t) {

}

// return 1 if all elements of A are equal to the corresponding elements of
// B, 0 otherwise
int equal(int m, int n, double *A, double *B) {

}

// Y = A * B
// A is m1 x n1m2. B is n1m2 x n2 Y is m1 x n2
void mult(int m1, int n1m2, int n2, double *A, double *B, double *Y) {

}

// The following functions and main() are provided for you
double* newMatrix(int m, int n) {
    double *mat;

    mat = (double*)malloc(m*n*sizeof(double));
    return mat;
}

double* newIdentityMatrix(int n) {
    double *mat = newMatrix(n, n);
    int i, j;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            mat[j+i*n] = (i==j);

    return mat;
}

int main(void) {
    double v1[3] = {4, 2, 1}; // 1x3 vector
    double v2[3] = {1, -2, 3}; // 1x3 vector
    double dp = dotproduct(3, v1, v2); // compute v1 dot v2
    double m1[9] = {0, 0, 2, 0, 0, 0, 2, 0, 0}; // 3x3 matrix
    double *m2 = newIdentityMatrix(3); // 3x3 identity matrix
    double *m3 = newMatrix(3, 3); // 3x3 matrix
    double m4[6] = {2, 3, 4, 5, 6, 7}; // 3x2 matrix
    double *m5 = newMatrix(3, 2); // 3x2 matrix
    double m6[6] = {6, 2, 5, 8, 2, 7}; // 2x3 matrix
    double *m7 = newMatrix(3, 2); // 3x2 matrix
    double *m8 = newMatrix(3, 2); // 3x2 matrix
    double expected[6] = {2, 1, 0, 1, 0, -1}; // expected result matrix
    int eq;

    add(3, 3, m1, m2, m3); // m3= m1+m2
    mult(3, 3, 2, m3, m4, m5); // m5= m3*m4 (3x2 result matrix)
    transpose(2, 3, m6, m7); // m7= m6^t
    linearcomb(3, 2, 1, 1-dp, m5, m7, m8); // m8= 1*m5 + (1-dp)*m7
    eq = equal(3, 2, m8, expected); // check if m8 is as expected

    return eq; // return 1 if so; 0 otherwise
}
