class BrowserHistory {
    
    list<string> dll;
    list<string>::iterator it;
public:
    BrowserHistory(string homepage) {
        dll.push_back(homepage);
        it=dll.begin();
    }
    
    void visit(string url) {
        
        list<string>::iterator temp = dll.end();
        temp--;
     
            while(it!=temp){
                dll.pop_back();
                temp=dll.end();
                temp--;
            }
        
         dll.push_back(url);
         it++;
        
    }
    
    string back(int steps) {
        
        while(steps&&it!=dll.begin()){
            it--;
            steps--;
        }
        return *it;
    }
    
    string forward(int steps) {
        
        while(steps&&it!=dll.end()){
            it++;
            steps--;
        }
        if(it==dll.end()) --it;
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */