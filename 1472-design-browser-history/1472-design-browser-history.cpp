class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>();
    }
    
    string back(int steps) {
        
        while(steps && history.size()!=1){
            string s = history.top();
            history.pop();
            future.push(s);
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        string res=history.top();
        while(steps && !future.empty()){
            res = future.top();
            future.pop();
            history.push(res);
            steps--;
        }
        return res;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */