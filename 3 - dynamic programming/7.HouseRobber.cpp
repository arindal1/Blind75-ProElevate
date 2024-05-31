class Solution {
public:
    int solvemem(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()) {
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int include=nums[index]+solvemem(nums,index+2,dp);
        int exclude=0+solvemem(nums,index+1,dp);
        dp[index]=max(include,exclude);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans=solvemem(nums,0,dp);
        return ans;
    }
};
