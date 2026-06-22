class Solution {
public:

    string enc(string s1){
        string toreturn = "";
        int count = 0;

        for(int i = s1.size()-1; i>0; --i){
            if(s1.at(i) == s1.at(i-1)){
                count++;
                continue;
            } else{
                if(count == 0){
                    toreturn = toreturn + s1.at(i);
                } else{
                    toreturn = toreturn + s1.at(i) + to_string(count);

                }
                count = 0;

            }

        }
        return toreturn;
    }

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        int i =0;
        while(i<s.size()){
            int j = i;
            while(s[j]!='#') j++;
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            j = i + length;
            res.push_back(s.substr(i,length));
            i=j;

            
        }

        return res;

    }
};
