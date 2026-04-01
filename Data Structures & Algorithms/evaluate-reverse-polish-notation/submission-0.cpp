class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();
                int res;
                if(tokens[i] == "+") res = a+b;
                else if(tokens[i] == "-") res = a-b;
                else if(tokens[i] == "*") res = a*b;
                else res = a/b;
                st.push(to_string(res));
            }
            else{
                st.push(tokens[i]);
            }
        }
        int ans = stoi(st.top());
        return ans;
    }
};
