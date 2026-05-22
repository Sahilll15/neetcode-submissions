class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // Initialize answer vector with zeros
        stack<int> st; // Stack to store indices

        for (int i = n - 1; i >= 0; --i) {
            // Pop elements from the stack while they are less than or equal to current temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            // If the stack is not empty, the top element is the next warmer day
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            // Push current index onto the stack
            st.push(i);
        }

        return ans;
    }
};
