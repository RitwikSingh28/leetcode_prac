#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        
        while(i < nums1.size() && j < nums2.size()) {
            int id1 = nums1[i][0], id2 = nums2[j][0];
            int val1 = nums1[i][1], val2 = nums2[j][1];

            if(id1 == id2) {
                result.push_back({id1, val1 + val2});
                i++, j++;
            } else if(id1 < id2) {
                result.push_back({id1, val1});
                i++;
            } else {
                result.push_back({id2, val2});
                j++;
            }
        }

        while (i < nums1.size()) {
            result.push_back(nums1[i++]);
        }

        while (j < nums2.size()) {
            result.push_back(nums2[j++]);
        }

        return result;
    }
};
