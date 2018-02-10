//
// Created by salahuddin on 2/10/18.
//

#include <cstring>
#include <iostream>


int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char *X, char *Y, int m, int n)
{
    char L[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                L[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }

    return L[m][n];
}


int lcs_main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    std::cout << "Length of lcs is: " << lcs(X, Y, m, n) << std::endl;

    return 0;
}

