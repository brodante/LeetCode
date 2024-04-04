class MinStack {
private:
    vector<int> a;
    vector<int> min;
public:
    MinStack()
    {
        min.push_back(INT_MAX);
    }
    
    void push(int val)
    {
        a.push_back(val);
        min.push_back(val<min.back()?val:min.back());        
    }
    
    void pop()
    {
        a.pop_back();
        min.pop_back();        
    }
    
    int top()
    {
        return a.back();        
    }
    
    int getMin()
    {
        return min.back();        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */