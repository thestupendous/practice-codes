// 1730 Find the Highest Altitude
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> heights(gain.size());
        int prev{0},curr{0};
        for(int g: gain) {
            curr=g+prev;
            heights.push_back(curr);
            prev=curr;
        }
        int ans=std::numeric_limits<int>::min();
        for(int h: heights) {
            ans = max(h,ans);
        }
        ans = max(ans,0);
        return ans;
    }
};
