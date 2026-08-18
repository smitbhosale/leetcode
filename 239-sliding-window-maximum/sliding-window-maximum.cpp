class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans;

        deque<int> dq;  // stores indices

        for (int right = 0; right < n; right++) {

            // Remove indices that are outside the window
            while (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // Add current element's index
            dq.push_back(right);

            // Window is complete
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};