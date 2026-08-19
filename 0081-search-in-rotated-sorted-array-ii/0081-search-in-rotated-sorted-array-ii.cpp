class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // Target mil gaya
            if(nums[mid] == target){
                return true;
            }

            // Duplicates ki wajah se sorted side decide nahi ho rahi
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            // LEFT side sorted hai
            if(nums[low] <= nums[mid]){

                // Target left sorted range mein hai
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            // RIGHT side sorted hai
            else{

                // Target right sorted range mein hai
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};