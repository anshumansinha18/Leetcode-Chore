class Solution {
public:
    bool check2(string s, string t){
         if(t.size()>s.size()) return false;
         string extract="";
        // cout<<s<<" "<<t<<endl;
        for(int i=0;i<t.size() && i<s.size();i++){
            extract+=s[i];
        }
        
        if(t==extract) return true;
        else return false;
    }
    bool check(string s, string t){
        
        string extract="";
        // cout<<s<<" "<<t<<endl;
        for(int i=0;i<t.size() && i<s.size();i++){
            extract+=s[i];
        }
        
        if(t>extract) return true;
        return false;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        int n = products.size();
        // for(int i=0;i<products.size();i++){
        //     cout<<products[i]<<" ";
        // }
        // cout<<endl;
        vector<vector<string>> res;
        string target="";
        for(int i=0;i<searchWord.size();i++){
            target+=searchWord[i];
            // cout<<i<<" target= "<<target;
            int low=0;
            int high=n-1;
          vector<string>x;
          while(low<high){
             int mid=low+(high-low)/2;
              // cout<<check(products[mid], target)<<" ";
             if(check(products[mid], target)){
                 low=mid+1;
             }else
                 high=mid;
           }
            // cout<<endl;
            int j=low;
           while(x.size()<3 && j<n && check2(products[j], target)){
               // cout<<check(products[j], target)<<" "<<products[j]<<" "<<target<<" "<<endl;
               x.push_back(products[j++]);
           }
           //  // cout<<endl;
           //  res.push_back(x);
            res.push_back(x);
        }
        
        return res;
    }
};