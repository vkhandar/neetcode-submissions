class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int size_n =temperatures.size();
        vector<int> result(size_n);
        st.push(0);

        for(int i = 1; i<size_n; ++i){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                result[st.top()] = i - st.top();
                st.pop();

            }
            st.push(i);
        }




        return result;
    }
};
