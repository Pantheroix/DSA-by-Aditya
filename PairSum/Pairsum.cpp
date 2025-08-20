// optimal approach
// for sorted array
#include <iostream>
#include <vector>

std::vector<int> PairSum(std::vector<int> nums, int target)
{
    std::vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        int Ps = nums[i] + nums[j];
        if (Ps < target)
        {
            i++;
        }
        else if (Ps > target)
        {
            j--;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};

    int target = 26;

    std::vector<int> ans = PairSum(nums, target);

    for (int i = 0; i < 2; i++)
    {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}