class Solution {
public:
    vector<int> leftMinimum(vector<int>& heights, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            res[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        return res;
    }
    vector<int> rightMinimum(vector<int>& heights, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            res[i] = st.empty() ? n-1 : st.top()-1;
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        vector<int> leftMin = leftMinimum(heights, n);
        vector<int> rightMin = rightMinimum(heights, n);
        for(int i=0; i<n; i++){
            int area = (rightMin[i] - leftMin[i] + 1)*heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
