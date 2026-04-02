class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        
        for(int i = 0; i < n; i++)
            cars[i] = {position[i], speed[i]};
        
        sort(cars.begin(), cars.end(), greater<>());  // sort by position descending
        
        stack<double> st;
        for(auto& [pos, spd] : cars){
            double time = double(target - pos) / spd;
            if(st.empty() || time > st.top())
                st.push(time);
        }
        return st.size();
    }
};
