class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        int m = points.size();
        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            int x = points[i][0];
            int y = points[i][1];
            pq.push({x*x + y*y, {x, y}});
        }
        while(k>0){
            if(!pq.empty()){
                auto top = pq.top(); pq.pop();
                int x = top.second.first;
                int y = top.second.second;
                ans.push_back({x,y});
            }
            k--;
        }
        return ans;
    }
};
