class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for (char c : s) {
            if (isalnum(c)) filtered += tolower(c);
        }
        int size = filtered.size();

        for(int i=0, j=size-1; i < size/2; i++, j--){
            if(filtered.at(i) != filtered.at(j)) return false;
        }

        return true;
        
    }
};
