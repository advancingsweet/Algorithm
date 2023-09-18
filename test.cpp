class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = -1, n, right = nums.size();
        n = right;
        while (left + 1 != right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target <= nums[mid])
                    right = mid;
                else
                    left = mid;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[n - 1])
                    left = mid;
                else
                    right = mid;
            }
        }
        return -1;
    }
};