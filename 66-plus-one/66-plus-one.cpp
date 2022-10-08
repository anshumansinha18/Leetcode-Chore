class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        
        if(digits[n-1]>0 && digits[n-1]<9)
        {
            digits[n-1]++;
            return digits;
        }
        else
        {
            int carry = 1;
            for(int i=n-1;i>=0;i--)
            {
                
                if(digits[i]==9)
                {
                    digits[i]= 0;
                    carry = 1;
                }
                else
                {
                    digits[i] += carry;
                    break;
                }
            }
            
            if(digits[0]==0)
            {
                vector<int> vec;
                vec.push_back(carry);
                
                for(int i=0;i<n;i++)
                    vec.push_back(digits[i]);
                
                return vec;
            }
            
            return digits;
        }
    }
};