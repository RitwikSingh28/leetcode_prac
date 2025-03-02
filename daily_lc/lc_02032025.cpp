#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        vector<vector<int>> merged2D;

        while(i < n1 && j < n2) {
            vector<int> mergedRow;
            if(nums1[i][0] == nums2[j][0]) {
                mergedRow = {nums1[i][0], nums1[i][1] + nums2[j][1]};
                i++, j++;
            } else if(nums1[i][0] < nums2[j][0]) {
                mergedRow = {nums1[i][0], nums1[i][1]};
                i++;
            } else {
                mergedRow = {nums2[j][0], nums2[j][1]};
                j++;
            }

            merged2D.push_back(mergedRow);
        }

        while (i < n1) {
            vector<int> mergedRow;
            mergedRow = {nums1[i][0], nums1[i][1]};
            i++;
            merged2D.push_back(mergedRow);
        }

        while (j < n2) {
            vector<int> mergedRow;
            mergedRow = {nums2[j][0], nums2[j][1]};
            j++;
            merged2D.push_back(mergedRow);
        }

        return merged2D;
    }
};
