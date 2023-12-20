class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       
        //   i
        //        j
        
        int n=strs.size();
        
        //find min length word:
        string minWord="";
        int minLength=201;
        for(int i=0;i<n;i++){
            if(strs[i].size()<minLength){
                minLength=strs[i].size();
                minWord=strs[i];
            }
        }
        
        //minWord= "a"
                 // i
        int i=0; //for minWord
        int j=0; //iterate over array
        // //flower, flow, flight
        //   j
        string res="";
        // cout<<minWord<<" "<<minLength<<endl;
        while(i<minLength){
            while(j<n){
                if(minWord[i]!=strs[j][i]){
                    return res;
                }
                j++;
            }
            
            res+=minWord[i];
            j=0;
            i++;
        }
        
        return res;
        
    }
};