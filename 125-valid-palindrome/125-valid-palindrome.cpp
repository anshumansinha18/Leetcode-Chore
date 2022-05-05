class Solution {
public:
    bool isAlphaNumeric(char c)
{
    return ((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z'));
}

char toLowerCase(char c)
{
    if(c>='A' && c<='Z')
        c = (char)(c + 32);
    return c;
}
bool isPali(string s)
{
    int start = 0;
    int end = s.length()-1;
    while(start<end)
    {
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
    }

    return true;
}
bool isPalindrome(string s) {
    int n = s.length();


   string s1;
    for(int i=0;i<n;i++)
    {
        if(isAlphaNumeric(s[i]))
        {
            s[i] = toLowerCase(s[i]);
            s1.push_back(s[i]);
        }
    }

    return isPali(s1);

}
};