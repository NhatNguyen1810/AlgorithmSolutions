class Solution {
public:
    vector<vector<int>> res; 
    void helperFunc(vector<int>& num, vector<int>& temp){
        if(num.size() == 0){
            res.push_back(temp); 
            return; 
        }
        
        for(int i = 0 ; i < num.size() ; i++){
            vector<int> tmpNum; 
            for(int j = 0 ; j < num.size() ; j++){
                if(i == j) continue; 
                tmpNum.push_back(num[j]); 
            }
            temp.push_back(num[i]); 
            helperFunc(tmpNum, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp; 
        helperFunc(nums, temp );
        return res; 
    }
};
