class Solution {
public:
    int f(int n,int m,int i,int j1,int j2,vector<vector<int>>& a,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2) return a[i][j1];
            else return a[i][j1]+a[i][j2];
        }
        if (dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2) value=a[i][j1];
                else value=a[i][j1]+a[i][j2];
                value+=f(n,m,i+1,j1+dj1,j2+dj2,a,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
        return f(n,m,0,0,m-1,grid,dp);
    }
};