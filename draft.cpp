    /// start of the fit function
    // 2D Array1 of the B`s --> FDD
    double fdd[n][n]{};
    
    // Fill the first column of FDD
    for (int i{0}; i < n; i++){
        fdd[i][0] = y1[i];
    }
    
    // Fill the rest of the columns of FDD
    for (int j{1}; j < n; j++){
        for (int i{0}; i < n-j; i++){
            fdd[i][j] = (fdd[i+1][j-1]-fdd[i][j-1])/(x1[i+j]-x1[i]);
        }
    }
    
    // Ex1tract the coefeecients 
    double b[n]{};
    for (int i{0}; i<n; i++){
        b[i] = fdd[0][i];
    }
    
    // print out the coeefecients' array1
    for (int count{0}; count < n; count++){
        std::cout 
        << "b_" << count << " = " << b[count] 
        << std::endl;
    }
    std::cout <<std::endl;
    /// end of the fit function
    
    /// start of the interpolate function
    double y_1[n2]{};
    
    for (int k{0}; k < n2; k++){
        y_1[k] = b[0];
        for (int l{1}; l < n; l++){
            int mult{1};
            for (int m{0}; m < l; m++){
                mult *= (x2[k]-x1[m]);
            }
            y_1[k] += (b[l]*mult);
        }
    }
    
    // print out the querry array1s
    for (int count{0}; count < n; count++){
        std::cout 
        << "x_" << count << " = " << x2[count]
        <<",\ty_" << count << " = " << y_1[count]
        << std::endl;
    }
    /// end of the interpolate function

