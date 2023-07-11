class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> minArr(n);
          
        int min = nums[0];
        
        for(int i=0;i<n;i++){
            minArr[i]=min;
            if(min>nums[i])
                min=nums[i];
        }
        stack<int> st;
      
        for(int k=0;k<n;k++){
            if(k<2){
                if(!st.empty()){
                    st.push(k);
                }else{
                    while(!st.empty() && nums[k]>nums[st.top()]){
                        st.top();
                    }
                    st.push(k);
                }
            }else{
                while(!st.empty() && nums[k]>=nums[st.top()])
                    st.pop();
                
                if(!st.empty() && minArr[st.top()]<nums[k]){
                    return true;
                }
                
                st.push(k);
            }
        }
        return false;
    }
};