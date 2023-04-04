#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> st;
    for (int num : nums) {
        st.insert(num);
    }
    
    return min(nums.size() / 2, st.size());
}