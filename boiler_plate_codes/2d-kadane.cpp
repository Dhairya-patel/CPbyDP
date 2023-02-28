class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int s[R][C] = {0}, ans = M[0][0];
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(i == 0 && j == 0)
                    s[i][j] = M[i][j];
                else if(i == 0)
                    s[i][j] = s[i][j - 1] + M[i][j];
                else if(j == 0)
                    s[i][j] = s[i - 1][j] + M[i][j];
                else
                    s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + M[i][j];
                // cout<<s[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        for(int i=0;i<R;i++)
        {
            for(int j=i;j<R;j++)
            {
                int temp = s[j][0], sum = 0, l = 0, r = 0;
                for(int k=0;k<C;k++)
                {
                    if(i == 0 && l == 0)
                        sum = s[j][k];
                    else if(i == 0)
                        sum = s[j][k] - s[j][l - 1];
                    else if(l == 0)
                        sum = s[j][k] - s[i - 1][k];
                    else
                        sum = s[j][k] - s[i - 1][k] - s[j][l - 1] + s[i - 1][l - 1];
                    if(temp < sum)
                    {
                        temp = sum;
                        r = k;
                    }
                    if(sum < 0)
                    {
                        sum = 0;
                        l = k + 1;
                    }
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};