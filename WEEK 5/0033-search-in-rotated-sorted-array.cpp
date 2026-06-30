class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        int pivot = low;

     
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            low = pivot;
            high = n - 1;
        } else {
            low = 0;
            high = pivot - 1;
        }

   
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};