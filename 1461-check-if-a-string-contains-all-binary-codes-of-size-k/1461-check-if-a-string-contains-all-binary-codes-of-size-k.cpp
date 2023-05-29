class Solution {
public:
int convert(string& res, int low, int high){
    int j=0, sum=0;
    for(int i=high;i>=low;i--)
        sum+= (int(res[i]-48)*(1<<j++));

    return sum;
}

bool hasAllCodes(string s, int k) {

    int n = s.size();
    unordered_set<int> st;
    int i=0;
    string res="";
   
    long long actualSum=0;
    while(i<n){
        res+=s[i];
        if(res.size()>=k){
            int number = convert(res, i-k+1, res.size()-1);
            st.insert(number);
        }
        i++;
    }
     if(st.size()==(1<<k)) return true;
    else return false;
}
};