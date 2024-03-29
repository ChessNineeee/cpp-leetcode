#include <fmt/ranges.h>
#include <vector>
using std::vector;

vector<int> sortArrayByParityII(const vector<int> &nums) {
  decltype(nums.size()) i = 0;
  decltype(nums.size()) j = 1;
  auto len = nums.size();

  while (true) {
    if (i >= len) {
      break;
    }

    if (j >= len) {
      break;
    }

    auto num_at_i = nums.at(i);
    if (num_at_i % 2 == 0) {
      i += 2;
      continue;
    }

    auto num_at_j = nums.at(j);
    if (num_at_j % 2 == 1) {
      j += 2;
      continue;
    }

    i += 2;
    j += 2;
  }

  return nums;
}

int main() {
  fmt::print("{}\n", sortArrayByParityII({}));
  return 0;
}