/*

    O(n^2) solution without using extra memory.
    Main idea: try to find an index (i) and another index j ( j > i ) so that
    nums[j] is the first number greater than nums[i]. When you find those indexes
    you make a swap, and then sort the rest of the numbers (nums[i+1,....n]) ascending order
*/


class Solution {
public:

    void ascending(vector<int>&nums, int start, int final)
    {
        int is_sorted = 0;
        while ( is_sorted == 0)
        {
            is_sorted = 1;
            for (int i = start; i <= final - 1 ; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    swap(nums[i], nums[i + 1]);
                    is_sorted = 0;
                }
            }
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n =  nums.size();
        const int INF = 1 << 30;
        if (n == 1)
        {
            return ;
        }

        if ( n == 2 )
        {
            swap(nums[0], nums[1]);
            return ;
        }

        int idx = n - 2;
        int index  = -1;
        while (1)
        {
            int choosen = INF;
            int original = nums[idx];
            index = -1;
            for ( int i = idx + 1 ; i < n ; i++ )
            {
                if (nums[i] > original)
                {
                    if (nums[i] <= choosen)
                    {
                        choosen = nums [i];
                        index = i;
                    }
                }
            }
            if (index == -1)
                idx--;
            else
                break;
            if (idx == -1)
            {
                break;
            }
        }
        if (idx == -1)
        {
            ascending(nums, 0, n - 1);
        }
        else
        {
            swap(nums[index], nums[idx]);
            ascending(nums, idx + 1, n - 1);
        }
    }
};