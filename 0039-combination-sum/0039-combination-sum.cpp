class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>&path, vector<vector<int>>& result){
        if(target==0){
            result.push_back(path);
            return;
        }
        for(int i=start; i<candidates.size(); ++i){
            if(candidates[i]>target)
                continue;
            path.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i, path, result);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(candidates, target, 0, path, result);
        return result;
    }
};