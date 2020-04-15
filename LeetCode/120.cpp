class Solution {
public:
    // this is for top-down approach
    int helperFunc(vector<vector<int>> triangle, int i, int j, int sum){
        int posInCurRow = triangle[i].size();
        if(i == triangle.size()-1){
            return sum;
        }
        int num1 = helperFunc(triangle, i+1, j, sum + triangle[i+1][j]);
        int num2; 
        int num3; 
        bool flag2= false; 
        bool flag3= false; 
        if(j+1 <= triangle[i+1].size()-1){
            num3 = helperFunc(triangle, i+1, j+1, sum + triangle[i+1][j+1]);
            flag3= true; 
        }
        return min(num1, num3);  
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[1000][1000];
        for(int i = 0 ; i < 1000;i++){
            for(int j = 0 ; j < 1000;j++){
                dp[i][j]= 0; 
            }
        }
        dp[0][0] = triangle[0][0];
        for(int i = 1 ; i < triangle.size() ; i++){
            for(int j = 0 ; j < triangle[i].size() ; j++){
                if(j-1 >= 0 && j <= triangle[i-1].size() - 1){
                    dp[i][j] = min(dp[i-1][j] + triangle[i][j], dp[i-1][j-1] + triangle[i][j]);
                }
                else if(j-1 < 0){
                    dp[i][j] = dp[i-1][j]+ triangle[i][j]; 
                }
                else if(j > triangle[i-1].size() - 1){
                    dp[i][j] = dp[i-1][j-1]+ triangle[i][j]; 
                }
            }
        }
        int res = 999999;
        for(int j = 0 ; j < triangle[triangle.size() - 1].size() ; j++){
            res = min(res, dp[triangle.size() - 1][j]);
        }
        return res; 
    }
};

