class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols= matrix[0].size();
        int row = -1;
        for(int i=0;i<rows;i++){
            if(target <= matrix[i][cols-1]){
                row = i;
                break;
            }
        }
        if(row == -1){return false;}
        int l = 0,r = cols-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[row][mid] == target){return true;}
            else if (matrix[row][mid] < target){l = mid + 1;}   
            else{r = mid - 1;}                
        }
        return false;
    }
};