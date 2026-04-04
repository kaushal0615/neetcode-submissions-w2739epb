class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n =  matrix[0].size();
        int targetRow;
        for(int i=0; i<m; i++){
            if(target == matrix[i][n-1]) return true;
            else if(target > matrix[i][n-1]) continue;
            else{
                targetRow = i;
                break;
            }
        }
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[targetRow][mid] == target) return true;
            else if(matrix[targetRow][mid] > target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};
