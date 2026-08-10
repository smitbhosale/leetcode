class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int water = 0;

        int i = 0;

        while (i < n - 1) {

            int j = i + 1;

            // Find the first wall >= current left wall
            while (j < n && height[j] < height[i]) {
                j++;
            }

            int right;

            // Case 1: found a wall >= left wall
            if (j < n) {
                right = j;
            }

            // Case 2: no wall >= left wall
            // Find the highest wall on the right
            else {
                right = i + 1;

                for (int k = i + 1; k < n; k++) {
                    if (height[k] > height[right]) {
                        right = k;
                    }
                }

                // If the highest wall is not useful
                // there is nothing more to process
                if (right == i + 1 && height[right] >= height[i]) {
                    // nothing special
                }
            }

            // Calculate water between i and right
            int waterLevel = min(height[i], height[right]);

            for (int k = i + 1; k < right; k++) {
                if (waterLevel > height[k]) {
                    water += waterLevel - height[k];
                }
            }

            // Move to the new right boundary
            i = right;
        }

        return water;
    }
};