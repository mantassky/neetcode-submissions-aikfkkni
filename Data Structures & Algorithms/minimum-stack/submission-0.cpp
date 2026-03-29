class MinStack {
public:
    stack<int> nums;
    stack<int> minNums;

    MinStack() {

    }
    
    void push(int val) {
        nums.push(val);
        if (minNums.empty()) minNums.push(val);
        else {
            int newMin = min(minNums.top(), val);
            minNums.push(newMin);
        }
    }
    
    void pop() {
        nums.pop();
        minNums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return minNums.top();
    }
};
