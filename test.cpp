class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = -1, right = nums.size(), pos; // 有问题
        while (left <= right)                    // 有问题
        {
            pos = left + ((right - left) / 2);
            if (nums[pos] == target)
                return pos;
            else if (nums[pos] < target)
                left = pos + 1; // 问题！
            else
                right = pos - 1; // 问题！
        }
        return pos + 1; // 有问题
    }
};