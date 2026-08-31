class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int sum = 0;
        int minSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            minSum = min(minSum, sum);
        }

        return 1 - minSum;
    }
};