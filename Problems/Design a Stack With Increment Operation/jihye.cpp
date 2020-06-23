using std::vector;

class CustomStack {
public:
    CustomStack(int maxSize) {
        size_limit = maxSize;
    }
    
    void push(int x) {
        if (stack.size() != size_limit) {
            stack.push_back(x);
        }
    }
    
    void printData() {
        for(auto num : stack)
            std::cout << num << " ";
        std::cout << "\n";
    }
    
    int pop() {
        int result;
        if (stack.size() == 0)
            result = -1;
        else {
            result = stack.back();
            stack.pop_back();
        }
        return result;
    }
    
    void increment(int k, int val) {
        if (stack.size() < k) {
            for (int i = 0; i < stack.size(); i++) {
                stack[i] += val;
            }
        }
        else {
            for (int i = 0; i < k; i++) {
                stack[i] += val;
            }
        }
    }
private:
    vector<int> stack;
    int size_limit;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
