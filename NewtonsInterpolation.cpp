#include <iostream>
struct Newtons {
    double x[100]{};
    double y[100]{};
    int n;
    double B[100]{};
    double y_query[100];
};

struct Newtons fit(double x[], double y[], int n){
    struct Newtons newtons_ploynomial;
    newtons_ploynomial.n = n;
    
    // setting the values of x and y
    for (int i{0}; i<n; i++){
        newtons_ploynomial.x[i] = x[i];
        newtons_ploynomial.y[i] = y[i];
    }
    
    // creating 2D Array1 for the B's --> FDD
    double fdd[n][n]{};
    
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

struct Newtons interpolate(struct Newtons newtons_ploynomial, double x[], int n2){
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

int main(){
    std::cout << "Part 3- Newton\'s Interpolation\n\n";
    
    // Define n
    const int n{10};
    
    // Define x1 values
    double x1[n]{-9.7979797979798, -8.58585858585859, -7.57575757575758, -7.37373737373737, -4.54545454545455, -3.93939393939394, 0.505050505050505, 2.32323232323232, 4.74747474747475, 8.78787878787879};
    
    // Define y1 values
    double y1[n]{98.1628240367145, 38.5844878743563, 2.83468291732757, -2.9177707077921, -41.4650638617581, -41.0421014553246, 20.3303208598587, 59.3541681481688, 106.087803862521, 127.252413946629};

    // Define x1 values
    double x2[]{-10.0, -9.39393939393939, -8.78787878787879, -7.57575757575758, -6.76767676767677, -6.36363636363636, -5.95959595959596, -5.75757575757576, -3.73737373737374, -2.72727272727273, -2.32323232323232, -1.71717171717172, -0.303030303030303, 2.12121212121212, 3.73737373737374, 4.14141414141414, 4.94949494949495, 5.55555555555556, 5.95959595959596, 6.56565656565656};
    
    // Define y1 values
    double y2[]{0.00990099009901, 0.011204971756063, 0.01278334057214, 0.01712560348488, 0.021366859893482, 0.024098785102569, 0.027384667827137, 0.029282852456372, 0.066809360536056, 0.118511263467189, 0.156313296438653, 0.253249270044701, 0.915895710681245, 0.181833361162131, 0.066809360536056, 0.055092439053181, 0.03921953093425, 0.031383184812088, 0.027384667827137, 0.022671703280816};
    
    // Define n2
    const int n2{sizeof(x2)/sizeof(x2[0])};
    
    // Fitting for dataset 1
    struct Newtons dataset1;
    dataset1 = fit(x1, y1, n); // will set the B's and N
    dataset1 = interpolate(dataset1, x1, n);
    // print the interpolation results
    for (int count{0}; count < n; count++){
        std::cout << "x_" << count << " = " << x1[count] 
        << ", y_" << count << " = " << y1[count]
        << ", predicted = " << dataset1.y_query[count] << std::endl;
    }
    std::cout <<std::endl;
    
    // Fitting for dataset 2
    struct Newtons dataset2;
    dataset2 = fit(x2, y2, n2); // will set the B's and N
    dataset2 = interpolate(dataset2, x2, n2);
    // print the interpolation results
    for (int count{0}; count < n; count++){
        std::cout << "x_" << count << " = " << x2[count] 
        << ", y_" << count << " = " << y2[count]
        << ", predicted = " << dataset2.y_query[count] << std::endl;
    }
    
        
    std::cout << std::endl;
    return 0;
}