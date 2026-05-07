class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        for(char t : tasks){
            mp[t]++;
        }
        for(auto ch : mp){
            pq.push(ch.second);
        }
        int intervals=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int &k : temp){
                if(k>0){
                    pq.push(k);
                }
            }
            if(pq.empty()){
                intervals += temp.size();
            }
            else{
                intervals += n+1;
            }
        }
        return intervals;
    }
};

