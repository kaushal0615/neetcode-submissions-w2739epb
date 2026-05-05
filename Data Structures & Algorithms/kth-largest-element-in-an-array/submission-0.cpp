class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while(!pq.empty() && k>0){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};
