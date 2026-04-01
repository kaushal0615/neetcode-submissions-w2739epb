class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[i] > st.top().first){
                int ind = st.top().second;
                int diff = i-ind;
                ans[ind] = diff;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};
