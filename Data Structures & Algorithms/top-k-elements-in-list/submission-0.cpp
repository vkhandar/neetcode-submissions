class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map<int, int> freq;

        for(int num: nums){
            freq[num]++;

        }
        
        vector<vector<int>> buckets(nums.size() + 1);

        for(auto& [num, count]: freq){
            buckets[count].push_back(num);
        }


        vector<int> result;
        for(int f = buckets.size() -1; f>= 0 && result.size() < k; --f){
            for(int num: buckets[f]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                    
                }
            }
        }

        return result;

    }
};
