class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        int left = 0;

        for(int right = 0; right<s.size(); ++right){
            if(mp.contains(s.at(right))){
                left = max(mp[s[right]] + 1, left);
            }
            mp[s[right]] = right;
            res = max(res, right-left+1);



        }

        return res;
        
    }
};
