//283
//https://leetcode.cn/problems/move-zeroes/description/
//方法1
//赋值
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int left = 0;
//        int right = 0;
//        for (left = 0; left < nums.size(); left++)
//        {
//            if (nums[left] != 0)
//            {
//                nums[right] = nums[left];
//                if (left != right)
//                {
//                    nums[left] = 0;
//                }
//                right++;
//            }
//        }
//    }
//};


//方法2
//交换元素
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int left = 0;
//        int right = 0;
//        for (left = 0; left < nums.size(); left++)
//        {
//            if (nums[left] != 0)
//            {
//                swap(nums[left], nums[right]);
//                right++;
//            }
//        }
//    }
//};


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for (left = 0; left < nums.size(); left++)
        {
            if (nums[left] != nums[right])
            {
                nums[right + 1] = nums[left];
                right++;
            }
        }
        return right;
    }
};

int main()
{
    vector<int> vec = { 0,0,1,1,1,2,2,3,3,4 };
    Solution s;
    int ret = s.removeDuplicates(vec);
    for (size_t i = 0;i<ret;i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}