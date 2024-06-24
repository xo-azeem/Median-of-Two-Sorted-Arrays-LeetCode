// Code

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0; int j = 0;
        vector<int> temp;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                temp.push_back(nums2[j]);
                j++;
            }
            else
            {
                temp.push_back(nums1[i]); 
                i++;
                temp.push_back(nums2[j]); 
                j++;
            } 
        }

        while(i < nums1.size())
        {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size())
        {
            temp.push_back(nums2[j]);
            j++;
        }  

        int n = temp.size();

        if (n % 2 != 0)
            return (double)temp[n / 2];
 
        return (double)(temp[(n - 1) / 2] + temp[n / 2]) / 2.0;
    }
};
