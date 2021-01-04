struct Newtons {
    long double x[100]{};
    long double y[100]{};
    int n;
    long double B[100]{};
    long double y_query[100];
};
struct Newtons newtons_fit(long double x[], long double y[], int n);
struct Newtons newtons_interpolate(struct Newtons newtons_ploynomial, long double x[], int n2);

