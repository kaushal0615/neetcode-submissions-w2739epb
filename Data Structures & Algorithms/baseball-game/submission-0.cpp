class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int ans=0;
        stack<int> st;
        for(auto &c:operations){
            if(c == "C"){
                if(!st.empty()) st.pop();
            }
            else if(c == "+"){
                int first = st.top();
                st.pop();
                int sum = first+st.top();
                st.push(first);
                st.push(sum);
            }
            else if(c == "D"){
                int prod = 2*st.top();
                st.push(prod);
            }
            else st.push(stoi(c));
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};