class FreqStack {
    unordered_map<int, stack<int>> m;
    unordered_map<int, int> freq;
    int maxFreq;
public:
    
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int x=m[maxFreq].top();
        freq[x]--;
        m[maxFreq].pop();
        if(m[maxFreq].empty()) maxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */