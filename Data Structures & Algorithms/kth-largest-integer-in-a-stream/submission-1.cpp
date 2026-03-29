class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> stream;

    KthLargest(int k, vector<int>& nums) {
        for (int x: nums) {
            stream.push(x);

            if (stream.size() > k) stream.pop();
        }

        if (stream.size() < k) stream.push(INT_MIN);
    }
    
    int add(int val) {
        stream.push(val);
        stream.pop();
        return stream.top();
    }
};
