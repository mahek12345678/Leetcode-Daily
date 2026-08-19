class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high){

            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high]){
                // minimum right side mein hai
                low = mid + 1;
            }
            else{
                // mid khud minimum ho sakta hai
                // ya minimum left side mein hai
                high = mid;
            }
        }

        return nums[low];
    }
};