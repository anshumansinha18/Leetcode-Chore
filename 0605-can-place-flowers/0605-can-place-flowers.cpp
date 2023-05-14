class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
       int size = flowerbed.size();
        if(size==1){
            if(n>0){
                if(flowerbed[0]==1)
                    return false;
                else return true;
            }
            else
                return true;
        }
        int i=0;
        while(i<size && n){
            if(flowerbed[i]==0){
                if(i==0){
                    if(flowerbed[i+1]==0){
                        flowerbed[i]=1;
                        n--;
                    }
                }
                else if(i==size-1){
                    if(flowerbed[i-1]==0){
                        flowerbed[i]=1;
                        n--;
                    }
                }
                else
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
            i++;
        }
        
        if(n<=0){
            return true;
        }
        else return false;
    }
};