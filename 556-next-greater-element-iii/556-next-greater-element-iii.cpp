class Solution {
public:
int nextGreaterElement(int x) {

    string s = to_string(x);
    int n = s.length();
    int i;
    for(i=n-1;i>0;i--)
    {
        if(s[i]>s[i-1]) break;
    }

    int j=i;
    if(j==0) return -1;

    map<char, int> m;
    j--;
    for(;j<n;j++)
        m[s[j]]++;

    char firstElem;
    int flag=0;
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(flag==1){
            firstElem = it->first;
            it->second--;
            break;
        }
        if(s[i-1]==it->first)
        {
           flag=1;
        }
    }
    string s1;
    s1.push_back(firstElem);

    for(auto p:m)
    {
        int c = p.second;
        while(c--)
            s1.push_back(p.first);
    }

    j=i-1;
    int k=0;
    for(;j<n;j++)
        s[j]=s1[k++];

    long long int sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum*10 + (long long int)(s[i]-48);
        if(sum>2147483647) return -1;
    }

    return sum;
    
}
};