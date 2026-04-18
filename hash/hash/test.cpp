//leetcode中的哈希表中的题目
//https://leetcode.cn/problem-list/hash-table/



//961.在长度2N的数组中找出重复N次的元素
//https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/submissions/
//方法1
//class Solution 
//{
//public:
//    int repeatedNTimes(vector<int>& nums) 
//    {
//        unordered_set<int> found;
//        for (int num : nums) {
//            if (found.count(num)) {
//                return num;
//            }
//            found.insert(num);
//        }
//        // 不可能的情况
//        return -1;
//    }
//};


//方法2
//class Solution {
//public:
//    int repeatedNTimes(vector<int>& nums) {
//        int n = nums.size() / 2;
//        unordered_map<int, int> umap;
//        for (auto e : nums)
//        {
//            umap[e]++;
//        }
//        int ret = 0;
//        for (auto e : umap)
//        {
//            if (e.second == n)
//            {
//                ret = e.first;
//                break;
//            }
//        }
//        return ret;
//    }
//};


//349.两个数组的交集
//https://leetcode.cn/problems/intersection-of-two-arrays/description/
//方法1
//class Solution 
//{
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
//    {
//        unordered_map<int, int> umap1, umap2;
//        vector<int> result;
//        for (auto e : nums1)
//        {
//            umap1[e]++;
//        }
//        for (auto e : nums2)
//        {
//            umap2[e]++;
//        }
//        for (auto e : umap1)
//        {
//            for (auto j : umap2)
//            {
//                if (e.first == j.first)
//                {
//                    result.push_back(e.first);
//                }
//            }
//        }
//        return result;
//    }
//};


//方法2
//class Solution 
//{
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
//    {
//        unordered_set<int> uset1, uset2;
//        vector<int> result;
//        for (auto e : nums1) 
//        {
//            uset1.insert(e);
//        }
//        for (auto e : nums2) 
//        {
//            uset2.insert(e);
//        }
//        for (auto e : uset1) 
//        {
//            if (uset2.find(e) != uset2.end())
//            {
//                result.push_back(e);
//            }
//        }
//        return result;
//    }
//};