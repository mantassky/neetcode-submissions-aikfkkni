class MedianFinder {
public:
    priority_queue<int> leftSide;
    priority_queue<int, vector<int>, greater<int>> rightSide;
    
    vector<int> median; // max size 2

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (median.empty()) {
            median.push_back(num);
            return;
        }

        if (median.size() == 2) {
            if (num < median[0]) {
                leftSide.push(num);
                rightSide.push(median[1]);

                median.pop_back();
            } else if (median[1] < num) {
                leftSide.push(median[0]);
                rightSide.push(num);

                median[0] = median[1];
                median.pop_back();
            } else { // between the medians
                leftSide.push(median[0]);
                rightSide.push(median[1]);

                median = { num };
            }
        } else {
            if (num <= median[0]) {
                leftSide.push(num);

                median.push_back(median[0]);
                median[0] = leftSide.top();
                leftSide.pop();
            } else {
                rightSide.push(num);

                median.push_back(rightSide.top());
                rightSide.pop();
            }
        }
    }
    
    double findMedian() {
        double res = 0;
        for (int num: median) res += num;

        return res / median.size();
    }
};
