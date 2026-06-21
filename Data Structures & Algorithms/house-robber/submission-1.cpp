class Solution {
private:
    int solve(vector<int>& nums, int cur){
        if(cur >= nums.size()){
            return 0;
        }

        return max(solve(nums, cur+1), nums[cur] + solve(nums, cur+2));


    }
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp (nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[nums.size()-1];
        
    }
};
