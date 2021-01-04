#include <iostream>
#include <part03.declerations.h>

struct Newtons newtons_fit(long double x[], long double y[], int n){
    struct Newtons newtons_ploynomial;
    newtons_ploynomial.n = n;
    
    // setting the values of x and y
    for (int i{0}; i<n; i++){
        newtons_ploynomial.x[i] = x[i];
        newtons_ploynomial.y[i] = y[i];
    }
    
    // creating 2D Array1 for the B's --> FDD
    long double fdd[n][n]{};
    
    // Fill the first column of FDD
    for (int i{0}; i < n; i++){
        fdd[i][0] = y[i];
    }
    
    // Fill the rest of the columns of FDD
    for (int j{1}; j < n; j++){
        for (int i{0}; i < (n-j); i++){
            fdd[i][j] = (fdd[i+1][j-1]-fdd[i][j-1])/(x[i+j]-x[i]);
        }
    }
    
    // Ex1tract the coefeecients 
    for (int i{0}; i<n; i++){
        newtons_ploynomial.B[i] = fdd[0][i];
    }
    
    // print out the coeefecients of newtons_ploynomial B`s values
    for (int count{0}; count < n; count++){
        std::cout 
        << "b_" << count << " = " << newtons_ploynomial.B[count] 
        << std::endl;
    }
    std::cout <<std::endl;
    
    return newtons_ploynomial;
}

struct Newtons newtons_interpolate(struct Newtons newtons_ploynomial, long double x[], int n2){
    const int n{newtons_ploynomial.n};
    
    for (int k{0}; k < n2; k++){
        newtons_ploynomial.y_query[k] = newtons_ploynomial.B[0];
        for (int l{1}; l < n; l++){
            int mult{1};
            for (int m{0}; m < l; m++){
                mult *= (x[k]-newtons_ploynomial.x[m]);
            }
            newtons_ploynomial.y_query[k] += (newtons_ploynomial.B[l]*mult);
        }
    }
    return newtons_ploynomial;
}
