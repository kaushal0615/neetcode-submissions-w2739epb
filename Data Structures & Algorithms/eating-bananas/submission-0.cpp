class Solution {
public:
    bool canFinish(vector<int> &piles, int mid, int h){
        long hours = 0;
        for(int p:piles){
            hours += (p+mid-1)/mid;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=0;
        for(int p:piles) high = max(high, p);
        while(low<high){
            int mid = low + (high-low)/2;
            if(canFinish(piles, mid, h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
