class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        long long s;
        int pre = 0;
        int length = 0, res = 0x3f3f3f3f;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            s += nums[i];
            while (s >= target)
            {
                length = i - pre + 1;
                res = min(length, res);
                s -= nums[pre++];
            }
        }
        return res == 0x3f3f3f3f ? 0 : res;
    }
};