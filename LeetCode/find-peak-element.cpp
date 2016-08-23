/*
    O(log n) solution. I used a aproach similar to binary search.
    Obvious soltion.
*/

class Solution {
public:
    int n;
    int check(vector <int> &nums, int st , int mid , int dr, int& sol)
    {
        if (mid - 1 >= 0)
        {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                sol =  mid;
                return 1;
            }
        }
        if (mid + 2 <= n)
        {
            if (nums[mid + 1] > nums[mid] && nums[mid + 1] > nums[mid + 2])
            {
                sol =  mid + 1;
                return 1;
            }
        }

        return -1;
    }
    int search(vector <int> &nums, int st, int dr, int &sol)
    {
        if (st > dr)
            return -1;
        if (st == dr)
        {
            return -1;
        }
        if (st ==  dr - 1)
        {
            return -1;
        }
        int mid = st + (dr - st) / 2;
        int search_st = search(nums, st, mid, sol);
        if (search_st != -1)
        {
            return 1;
        }
        int search_dr = search(nums, mid + 1, dr, sol);
        if (search_dr != -1)
        {
            return 1;
        }
        return check(nums, st , mid, dr, sol);

    }
    int findPeakElement(vector<int>& nums) {
        n = nums.size() - 1;
        if (n == 0)
        {
            return 0;
        }
        if ( n == 1)
        {
            if (nums[0] > nums[1])
                return 0;
            return 1;
        }
        if (nums[0] > nums [1])
            return 0;
        if (nums[n - 1] < nums [n])
        {
            return n;
        }
        int sol = -1;
        int find = search(nums, 0, n, sol);
        return sol;
    }
};