class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        priority_queue<int> pq;
        for(int num:stones){
            pq.push(num);
        }
        while(pq.size()>1){
            if(pq.size() == 1){
                ans = pq.top();
                break;
            }
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(x != y) pq.push(x-y);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
