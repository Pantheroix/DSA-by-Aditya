#include <iostream>
#include <vector>

int MJE(std::vector<int> MJ)
{
    int n = MJ.size();
    int freq = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = MJ[i];
        }
        if (ans == MJ[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

int main()
{

    std::vector<int> MJ = {3, 3, 3, 3, 1, 1};

    int res = MJE(MJ);

    std::cout << res << std::endl;
    return 0;
}