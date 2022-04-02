class Solution {
public:
   bool validPalindrome(string s) {
    int start=0;
    int end=s.length()-1;

    int count1=0;
    while(start<end) {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            count1++;
            start++;
        }
    }
    int count2=0;
    start=0;
    end = s.size()-1;
    while(start<end) {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            count2++;
            end--;
        }
    }

    if(count1>1 && count2>1) return false;
    else return true;
}
};