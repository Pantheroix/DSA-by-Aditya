#include <iostream>
int main()
{
  int nums[8] = {3, -4, 5, -4, -1, 7, -8};

  int sum = 0;
  int maxi = INT_MIN;
  for (int i = 0; i < sizeof(nums) / 4; i++)
  {
    sum = sum + nums[i];
    maxi = std::max(sum, maxi);
    if (sum < 0)
    {
      sum = 0;
    };
  };

  std::cout << maxi << std::endl;

  return 0;
}
