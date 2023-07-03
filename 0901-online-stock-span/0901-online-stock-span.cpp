class StockSpanner {
    stack<int> st;
    vector<int> arr;
    int i;
public:
    StockSpanner() {
          i=0;
    }
    
    int next(int price) {
       if(st.empty()){
           st.push(i++);
           arr.push_back(price);
           return 1;
       }else{
           while(!st.empty() && price>=arr[st.top()]){
               st.pop();
           }
         
           arr.push_back(price);
           int x = 1;
           if(!st.empty()){
             x = i-st.top();
           }
           else x = i+1;
           st.push(i);
           i++;
           return x;
       }
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */