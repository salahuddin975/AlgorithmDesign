#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>


int lcs(char *X, char *Y, int m, int n)
{
	std::vector< std::vector<char> > L(m+1, std::vector<char>(n+1));

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                L[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else{
                L[i][j] = std::max(L[i-1][j], L[i][j-1]);
            }
        }
    }

    return L[m][n];
}


void lcs_main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    std::cout << "Length of lcs is: " << lcs(X, Y, m, n) << std::endl;
}

