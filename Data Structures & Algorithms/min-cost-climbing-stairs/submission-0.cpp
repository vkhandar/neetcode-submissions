class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty()) return 0;
        vector<int> dp(cost.size()+1);
        
        for(int i = 2; i<=cost.size(); ++i){
            dp[i] = min(dp[i-1] + cost[i-1], cost[i-2] + dp[i-2]);
        }
        return dp[cost.size()];

        
        
    }
};
