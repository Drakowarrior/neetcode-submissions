class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        stack<int> stk;
        int res = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int mid = height[stk.top()];
                stk.pop();
                if (!stk.empty()) {
                    int right = height[i];
                    int left = height[stk.top()];
                    int h = min(right, left) - mid;
                    int w = i - stk.top() - 1;
                    res += h * w;
                }
            }
            stk.push(i);
        }

        return res;
    }
};