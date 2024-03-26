#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    if (a>b)
        return a;
    else  
        return b;
}

// Function to find the length of LCS of three sequences
int lcsOf3(char *X, char *Y, char *Z, int m, int n, int o) {
    int L[m + 1][n + 1][o + 1];

    // Build the array L[][][] in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= o; k++) {
                if (i == 0 || j == 0 || k == 0)
                    L[i][j][k] = 0;
                else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1])
                    L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
                else
                    L[i][j][k] = max(max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
            }
        }
    }

    // LCS is stored in L[m][n][o]
    return L[m][n][o];
}

// Main function
int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";
    char Z[] = "BADACB";

    int sizeX = strlen(X);
    int sizeY = strlen(Y);
    int sizeZ = strlen(Z);

    printf("Length of LCS of three sequences is %d\n", lcsOf3(X, Y, Z, sizeX, sizeY, sizeZ));

    return 0;
}
