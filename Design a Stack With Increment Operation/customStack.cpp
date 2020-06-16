class CustomStack {
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() >= maxSize)
            return;
        
        stack.push_back(x);
    }
    
    int pop() {
       if (stack.size() == 0) 
           return -1;
        
        int ret = stack.back();
        stack.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        if ((k == 0)
           || (stack.size() == 0))
            return;
        
        int count = k;
        if (count > stack.size())
            count = stack.size();
        
        for(int i = 0; i < count; i++)
        {
            stack[i] = stack[i] + val;
        }
    }
private:
    int maxSize;
    std::vector<int> stack;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */