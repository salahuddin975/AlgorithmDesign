#include <iostream>
#include <climits>
#include <vector>


int MatrixChainOrder(int p[], int n)
{
    std::vector< std::vector<int> > M(n, std::vector<int> (n));        // int M[n][n]; 
    int i, j, k, L, cost;
  
    for (i=1; i<n; i++)
        M[i][i] = 0;                      // no joining cost for same matrix
 
    for (L=2; L<n; L++)                   // L is chain length
    {
        for (i=1; i<n-L+1; i++)           // i is start index of the chain
        {
            j = i+L-1;                    // j is last index of the chain     
            M[i][j] = INT_MAX;

            for (k=i; k<=j-1; k++)        // k is joining index of two matrices of the chain
            {
                cost = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];   // p[i..k..j]  first matrix cost + second matrix cost + matrix multiplication cost to make single matrix
                if (cost < M[i][j])
                    M[i][j] = cost;
            }
        }
    }
 
    return M[1][n-1];
}

 
int main()
{
    int arr[] = {1, 2, 3, 4};            // three matrices: [1, 2], [2, 3], [3, 4] 
    int size = sizeof(arr)/sizeof(arr[0]);
 
    std::cout << "Minimum number of multiplications is: " << MatrixChainOrder(arr, size) << std::endl;
 
    return 0;
}
