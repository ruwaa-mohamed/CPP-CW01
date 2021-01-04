#include <iostream>
#include <cmath>
#include <part03.declerations.h>

int main(){
    ///////////////////////////////////////////////////////////////////////////
    std::cout << "Part 3- Interpolation\n";
    
    // Reading the 1st dataset (n, x1, and y1)
    const int n{10};
    long double x1[n]{-9.7979797979798, -8.58585858585859, -7.57575757575758, -7.37373737373737, -4.54545454545455, -3.93939393939394, 0.505050505050505, 2.32323232323232, 4.74747474747475, 8.78787878787879};
    long double y1[n]{98.1628240367145, 38.5844878743563, 2.83468291732757, -2.9177707077921, -41.4650638617581, -41.0421014553246, 20.3303208598587, 59.3541681481688, 106.087803862521, 127.252413946629};

    // Reading the 2nd dataset (n2, x2, and y2)
    long double x2[]{-10.0, -9.39393939393939, -8.78787878787879, -7.57575757575758, -6.76767676767677, -6.36363636363636, -5.95959595959596, -5.75757575757576, -3.73737373737374, -2.72727272727273, -2.32323232323232, -1.71717171717172, -0.303030303030303, 2.12121212121212, 3.73737373737374, 4.14141414141414, 4.94949494949495, 5.55555555555556, 5.95959595959596, 6.56565656565656};
    long double y2[]{0.00990099009901, 0.011204971756063, 0.01278334057214, 0.01712560348488, 0.021366859893482, 0.024098785102569, 0.027384667827137, 0.029282852456372, 0.066809360536056, 0.118511263467189, 0.156313296438653, 0.253249270044701, 0.915895710681245, 0.181833361162131, 0.066809360536056, 0.055092439053181, 0.03921953093425, 0.031383184812088, 0.027384667827137, 0.022671703280816};
    const int n2{sizeof(x2)/sizeof(x2[0])};
    
    const int n3{4};
    long double x3[n3]{3.0, 4.5, 7.0, 9.0};
    long double y3[n3]{2.5, 1.0, 2.5, 0.5};
    
    ///////////////////////////////////////////////////////////////////////////
    /* std::cout << "**Newton's Interpolation**\n\n";
    // Fitting for dataset 1
    std::cout << "For dataset #1:\n";
    struct Newtons dataset1;
    dataset1 = newtons_fit(x1, y1, n);  //will set the B's and N
    dataset1 = newtons_interpolate(dataset1, x1, n);
    // print the interpolation results
    //for (int count{0}; count < n; count++){
    //    std::cout << "x_" << count << " = " << x1[count] 
    //    << ", y_" << count << " = " << y1[count]
    //    << ", predicted = " << dataset1.y_query[count] << std::endl;
    //}
    std::cout <<std::endl;
    
    // Fitting for dataset 2
    std::cout << "For dataset #2:\n";
    struct Newtons dataset2;
    dataset2 = newtons_fit(x2, y2, n2);  //will set the B's and N
    dataset2 = newtons_interpolate(dataset2, x2, n2);
     //print the interpolation results
    //for (int count{0}; count < n2; count++){
        //std::cout << "x_" << count << " = " << x2[count] 
        //<< ", y_" << count << " = " << y2[count]
        //<< ", predicted = " << dataset2.y_query[count] << std::endl;
    //}*/
    ///////////////////////////////////////////////////////////////////////////
    std::cout << "\n**Spline Interpolation**\n\n";
    
    // we have 4(n-1) unkowns
    // create output matrix
    long double cspline_matrix[4*(n3-1)][4*(n3-1)+1]{0.0};
    
    // group 1 of the conditions: Function values must be equal at interior knots (2n‐4 conditions)
    int j{0};
    for (int i{0}; i < (2*n3-4); i++){ 
        /* a, b, c, d 
         * a = x^3
         * b = x^2
         * c = x
         * d = 1*/
        long double v{x3[i/2]};
        cspline_matrix[i][j] = std::pow(v, 3);
        j++;
        cspline_matrix[i][j] = std::pow(v, 2);
        j++;
        cspline_matrix[i][j] = v;
        j++;
        cspline_matrix[i][j] = 1.0;
        j++;
        cspline_matrix[i][(4*(n3-1)+1)] = y3[i/2];
        if (i%2 != 0){
            j -=4;
        }
    }
    
    
    for (int i{0}; i < (4*(n3-1)); i++){
        for (int j{0}; j<(4*(n3-1)+1); j++){
            std::cout << cspline_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    return 0;
}