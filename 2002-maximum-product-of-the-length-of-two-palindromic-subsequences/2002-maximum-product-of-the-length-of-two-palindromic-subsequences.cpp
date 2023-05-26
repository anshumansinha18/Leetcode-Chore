class Solution {
public:
    bool checkPal(string s){
    int start=0;
    int end = s.size()-1;
    while(start<end){
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
    }

    return true;
}

int maxProduct(string s) {

    vector<pair<int, int>> vec;
     int n= s.size();
     for(int i=1;i<(1<<n);i++){
         string sub = "";

         for(int j=0;j<=n;j++){
             if(i & (1<<j)){
                 sub+=s[j];
             }
         }

         if(checkPal(sub)) {
             vec.push_back(make_pair(i, sub.size()));
         }

     }
    int res = 0;
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            if(!(vec[i].first & vec[j].first)){
                res = max(res, vec[i].second*vec[j].second);
            }
        }
    }
    return res;


}
};