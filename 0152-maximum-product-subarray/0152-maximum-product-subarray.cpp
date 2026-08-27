class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currentMax = nums[0];
        int currentMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){

            int oldMax = currentMax;
            int oldMin = currentMin;

            currentMax = max(nums[i],
                         max(oldMax * nums[i],
                             oldMin * nums[i]));

            currentMin = min(nums[i],
                         min(oldMax * nums[i],
                             oldMin * nums[i]));

            ans = max(ans, currentMax);
        }

        return ans;
    }
};