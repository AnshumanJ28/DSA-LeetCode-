class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void h(vector<int>& arr, int start,int sum, int target){
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        for(int i =start;i<arr.size();i++){
            if(i>start && arr[i] == arr[i-1]) {continue;}
            if(sum+arr[i]>target){break;}
            curr.push_back(arr[i]);
            h(arr,i+1,sum+arr[i],target);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        h(candidates,0,0,target);
        return ans;
    }
};