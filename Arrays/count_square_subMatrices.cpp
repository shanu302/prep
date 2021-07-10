// Approach 1; TC: O(M*N) SC: O(M*N)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        int res = 0;
        for(int i=0; i<n;i++){
          //intilize first row;
            dp[0][i] = matrix[0][i];
            res+=dp[0][i];
        }
        for(int i=1; i<m;i++){
          // for first column;
            dp[i][0] = matrix[i][0];
            res+=dp[i][0];
        }
        for(int i=1; i<m;i++){
            for(int j=1; j<n;j++){
                if(matrix[i][j]==1){
                  // at any point dp[[i][j] contains number of square sub. matrices ending there;
                    dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
                }else{
                    dp[i][j] = 0;
                }
                res+=dp[i][j];
            }
        }
        return res;
    }
};


// Approach 2 TC: O(M*N); SC: O(1) (modifying matrix array)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for(int i=0; i<n;i++){
           res+= matrix[0][i];
            
        }
        for(int i=1; i<m;i++){
            res+=matrix[i][0];
        }
        for(int i=1; i<m;i++){
            for(int j=1; j<n;j++){
                if(matrix[i][j]==1){
                    matrix[i][j] = min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1])) + 1;
                }else{
                    matrix[i][j] = 0;
                }
                res+=matrix[i][j];
            }
        }
        return res;
    }
};
