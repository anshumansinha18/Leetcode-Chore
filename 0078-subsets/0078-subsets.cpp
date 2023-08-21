class Solution {
public:
    vector<vector<int>> res;
    void generate(vector<int> input, vector<int> output){
        if(input.size()==0){
            res.push_back(output);
            return;
        }
        
        vector<int> op1 = output;
        vector<int> op2 = output;
        op2.push_back(input[0]);
        input.erase(input.begin());
        generate(input, op1);
        generate(input, op2);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        generate(nums, {});
        return res;
    }
};