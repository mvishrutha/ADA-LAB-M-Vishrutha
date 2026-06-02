int findMaxForm(char **strs, int strsSize, int m, int n) {
    int dp[101][101] = {0};

    for(int k = 0; k < strsSize; k++) {
        int zeros = 0, ones = 0;

        for(int i = 0; strs[k][i] != '\0'; i++) {
            if(strs[k][i] == '0')
                zeros++;
            else
                ones++;
        }

        for(int i = m; i >= zeros; i--) {
            for(int j = n; j >= ones; j--) {
                if(dp[i - zeros][j - ones] + 1 > dp[i][j])
                    dp[i][j] = dp[i - zeros][j - ones] + 1;
            }
        }
    }

    return dp[m][n];
}
