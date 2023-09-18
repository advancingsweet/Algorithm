class Solution
{
public:
    int mySqrt(int x)
    {
        double left = 0, right = x + 1;
        double mid;
        while (left - right >= 0.000001)
        {
            mid = left + (right - left) / (2 * 1.0);
            double val = (x * 1.0) / mid;
            if (val == mid)
                break;
            else if (val > mid)
                left = mid;
            else
                right = mid;
        }
        int val = (int)mid;
        return val;
    }
};