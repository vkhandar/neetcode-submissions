class Solution {
public:

    bool anagramChecker(string val1, string val2){
        if(val1.length() != val2.length()) return false;

        sort(val1.begin(), val1.end());
        sort(val2.begin(), val2.end());

        return val1 == val2;
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> toreturn;
        vector<string> first = {strs[0]};
        toreturn.push_back(first);


        for(int i =1; i< strs.size(); ++i){
            bool check = true;
            for(int j = 0; j<toreturn.size(); ++j){
                if(anagramChecker(toreturn[j][0], strs[i])){
                    toreturn[j].push_back(strs[i]);
                    check = false;
                    continue;
                    
                }
            }

            if(check){
                vector<string> second = {strs[i]};
                toreturn.push_back(second);


            }

        }
        return toreturn;

        
    }
};
