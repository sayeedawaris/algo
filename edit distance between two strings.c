#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int editDistance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D array to store the minimum number of operations
    int dp[m + 1][n + 1];

    // Initialize the first row and first column
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Calculate minimum number of operations
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                // Consider three cases: insertion, deletion, and substitution
                dp[i][j] = 1 + min(dp[i - 1][j],       // deletion
                                   dp[i][j - 1],       // insertion
                                  dp[i - 1][j - 1]); // substitution
            }
        }
    }
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return dp[m][n];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    printf("Edit distance between \"%s\" and \"%s\" is: %d\n", s1, s2, editDistance(s1, s2));
    return 0;
}
