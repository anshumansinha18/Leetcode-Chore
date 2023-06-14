class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int n = people.size();
        int sum=0;
        int count=0;
        
        int i=0, j=n-1;
        while(i<=j){
         
            if(people[i]+people[j]<=limit){
                j--;
                i++;
            }else
                j--;
            
            count++;
            
        }
        
        return count;
    }
};