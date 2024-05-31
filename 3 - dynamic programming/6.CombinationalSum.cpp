class Solution {
public:
void solve(int ind, vector<vector<int>>& ans,int sum , int k , int n, vector<int>& result )
{
    if(sum == n && k ==0 )
    {
        ans.push_back(result);
        return ;
    }
    if(sum > n)
    {
        return ;
    }
    for(int i =ind ; i < 10 ;i++)
    {
        if(i > n)
        {
            break;
        }
        result.push_back(i);
        solve(i+1,ans,sum+i,k-1,n,result);
        result.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>result;
        solve(1,ans,0 , k, n , result) ;   
        return ans;
    }
};