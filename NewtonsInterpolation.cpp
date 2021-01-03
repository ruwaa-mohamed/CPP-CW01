#include <iostream>

int main(){
    std::cout << "Part 3- Newton\'s Interpolation\n\n";
    
    // Define n
    const int n{10};
    
    // Define x values
    double x[n]{-9.7979797979798, -8.58585858585859, -7.57575757575758, -7.37373737373737, -4.54545454545455, -3.93939393939394, 0.505050505050505, 2.32323232323232, 4.74747474747475, 8.78787878787879};
    
    // Define y values
    double y_true[n]{98.1628240367145, 38.5844878743563, 2.83468291732757, -2.9177707077921, -41.4650638617581, -41.0421014553246, 20.3303208598587, 59.3541681481688, 106.087803862521, 127.252413946629};

    
    // print out the arrays!  ==> not needed actually,
    //for (int count{0}; count < n; count++){
    //    std::cout 
    //    << "x_" << count << " = " << x[count]
    //    <<",\ty_" << count << " = " << y_true[count] 
    //    << std::endl;
    //}
    
    /// start of the fit function
    // 2D Array of the B`s --> FDD
    double fdd[n][n]{};
    
    // Fill the first column of FDD
    for (int i{0}; i < n; i++){
        fdd[i][0] = y_true[i];
    }
    
    // Fill the rest of the columns of FDD
    for (int j{1}; j < n; j++){
        for (int i{0}; i < n-j; i++){
            fdd[i][j] = (fdd[i+1][j-1]-fdd[i][j-1])/(x[i+j]-x[i]);
        }
    }
    
    
    // Print out the FDD matrix
    //for (int i{0}; i < n; i++){
    //    for (int j{0}; j<n; j++){
    //        std::cout << fdd[i][j] << "\t";
    //    }
    //    std::cout << std::endl;
    //}
    
    // Extract the coefeecients 
    double b[n]{};
    for (int i{0}; i<n; i++){
        b[i] = fdd[0][i];
    }
    // print out the coeefecients' array
    for (int count{0}; count < n; count++){
        std::cout 
        << "b_" << count << " = " << b[count] 
        << std::endl;
    }
    std::cout <<std::endl;
    /// end of the fit function
    
    // Define x_query
    double x_query[]{-9.39393939393939, -8.78787878787879, 
    -6.76767676767677, -6.36363636363636, -5.95959595959596, 
    -5.75757575757576, -3.73737373737374, -2.72727272727273,
    -2.32323232323232, -1.71717171717172, -0.303030303030303,
    2.12121212121212, 3.73737373737374, 4.94949494949495};
    
    /// start of the interpolate function
    const int n2{sizeof(x_query)/sizeof(x_query[0])};
    double y_query[n2]{};
    
    for (int k{0}; k < n2; k++){
        y_query[k] = b[0];
        for (int l{1}; l < n; l++){
            int mult{1};
            for (int m{0}; m < l; m++){
                mult *= (x_query[k]-x[m]);
            }
            y_query[k] += (b[l]*mult);
        }
    }
    
    // print out the querry arrays
    for (int count{0}; count < n; count++){
        std::cout 
        << "x_" << count << " = " << x_query[count]
        <<",\ty_" << count << " = " << y_query[count] 
        << std::endl;
    }
    /// end of the interpolate function
    
    std::cout << std::endl;
    return 0;
}