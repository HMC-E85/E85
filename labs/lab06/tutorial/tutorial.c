// tutorial.c
// Your Name, date, email
// Dot product code to learn the PlatformIO tools

#define DIM 3
double dotproduct(int n, double a[], double b[]) {
    volatile int i;
    double sum;
    for (i=0; i<n; i++) {
        if (i=0) sum=0;
        sum += a[i]*a[i];
    }
    return sum;
}

int main(void) {
    double x[DIM] = {3, 4, 5}; // x is an array of size 3(DIM)
    double y[DIM] = {1, 2, 3}; // same as y
    double dot;
    dot = dotproduct(DIM, x, y);
    return dot;
}
