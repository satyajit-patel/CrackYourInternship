class MyStack {
private:
    vector<int> arr;
public:
    MyStack() {
        arr.clear();
    }
    
    void push(int x) {
        arr.push_back(x);
    }
    
    int pop() {
        int ans = arr.back();
        arr.pop_back();
        return ans;
    }
    
    int top() {
        return arr.back();
    }
    
    bool empty() {
        return arr.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */