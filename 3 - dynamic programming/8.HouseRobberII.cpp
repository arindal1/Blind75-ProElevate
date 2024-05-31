class Solution {
private:
   
    int solveTabulation(int size, vector<int> &nums)
    {
        vector<int> dp(size+1, 0);
        dp[0] = nums[0];

        for(int i=1;i<=size;i++)
        {
            int include;
            if(i-2 >= 0)
                include = nums[i] + dp[i-2] ;
            else
                include = nums[i];
                
            int exclude = 0 + dp[i-1] ;
            dp[i] = max(include, exclude);
        }

        return dp[size];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];

        int index = nums.size()-1;
        vector<int> nums1, nums2;

        for(int i=1;i<nums.size();i++)
            nums1.push_back(nums[i]);

        for(int i=0;i<nums.size()-1;i++)
            nums2.push_back(nums[i]);
    
        int ans = solveTabulation(nums1.size()-1, nums1);
        int ans2 = solveTabulation(nums2.size()-1, nums2);

        return max(ans, ans2);
    }
};