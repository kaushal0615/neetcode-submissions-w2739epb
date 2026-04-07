class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[high] < nums[mid]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(nums[low] == target) return low;
        int pivot = low;
        int left, right;
        if(target >= nums[pivot] && target <= nums[n-1]){
            left = pivot; right = n-1;
        }
        else{
            left = 0; right = pivot-1;
        }
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};
