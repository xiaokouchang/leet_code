//283
//移动零
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


//1089
//复写零
//https://leetcode.cn/problems/duplicate-zeros/
//方法1
//right=-1;
//class Solution 
//{
//public:
//    void duplicateZeros(vector<int>& arr) 
//    {
//        //先找到最后一个数
//        int cur = 0;
//        int dest = -1;
//        int n = arr.size();
//        while (cur < n)
//        {
//            if (arr[cur]) dest++;
//            else dest += 2;
//            if (dest >= n - 1) break;
//            cur++;
//        }
//        //处理边界情况
//        if (dest == n)
//        {
//            arr[n - 1] = 0;
//            cur--;
//            dest -= 2;
//        }
//        //从后向前完成复写操作
//        while (cur >= 0)
//        {
//            if (arr[cur]) arr[dest--] = arr[cur--];
//            else
//            {
//                arr[dest--] = 0;
//                arr[dest--] = 0;
//                cur--;
//            }
//        }
//    }
//};


//方法2
//right=0;
//class Solution
//{
//public:
//    void duplicateZeros(vector<int>& arr) 
//    {
//        int left = 0;
//        int right = 0;
//        int n = arr.size();
//        // 找到最后一个数字
//        while (left < n) 
//        {
//            if (arr[left] != 0) 
//            {
//                right++;
//            }
//            else 
//            {
//                right += 2;
//            }
//            if (right > n - 1) 
//            {
//                right--;
//                break;
//            }
//            left++;
//        }
//        // 处理边界条件
//        if (right >= n) 
//        {
//            arr[n - 1] = 0;
//            left--;
//            right -= 2;
//        }
//        while (left >= 0) 
//        {
//            if (arr[left] != 0) 
//            {
//                arr[right--] = arr[left--];
//            }
//            else 
//            {
//                arr[right--] = 0;
//                arr[right--] = 0;
//                left--;
//            }
//        }
//    }
//};


//方法3
//class Solution 
//{
//public:
//    void duplicateZeros(vector<int>& arr)
//    {
//        int n = arr.size();
//        int i = 0;
//        int j = 0;
//        while (j < n)
//        {
//            if (!arr[i])
//            {
//                j++;
//            }
//            j++;
//            i++;
//        }
//        j--;
//        i--;
//        while (i >= 0)
//        {
//            if (j < n)
//            {
//                arr[j] = arr[i];
//            }
//            if (arr[i] == 0 && --j >= 0)//第1个为假,条件错误,不执行--j>=0
//            {
//                arr[j] = 0;
//            }
//            j--;
//            i--;
//        }
//    }
//};


//方法4
//class Solution 
//{
//public:
//    void duplicateZeros(vector<int>& arr) 
//    {
//        int count = 0;//统计0的个数
//        int n = arr.size();
//        for (auto e : arr)
//        {
//            if (e == 0)
//            {
//                count++;
//            }
//        }
//        int i = n - 1;
//        int j = n + count - 1;
//        while (i >= 0 && j >= 0)
//        {
//            if (arr[i] == 0)
//            {
//                if (j < n)
//                {
//                    arr[j] = 0;
//                }
//                j--;
//                if (j < n)
//                {
//                    arr[j] = 0;
//                }
//            }
//            else
//            {
//                if (j < n)
//                {
//                    arr[j] = arr[i];
//                }
//            }
//            i--;
//            j--;
//        }
//    }
//};


//方法5
//class Solution 
//{
//public:
//    void duplicateZeros(vector<int>& arr) 
//    {
//        int n = arr.size();
//        int top = 0;
//        int low = -1;
//        while (top < n)
//        {
//            low++;
//            if (arr[low] == 0)
//            {
//                top += 2;
//            }
//            else
//            {
//                top++;
//            }
//        }
//        //处理边界
//        int j = n - 1;
//        if (top == n + 1)//最后一个位置为0,超出数组1个,修改位置
//        {
//            arr[j] = 0;//只需要填充1个0;
//            //最后一个位置不需要填充
//            j--;
//            low--;
//        }
//        //填充元素
//        while (j >= 0)
//        {
//            arr[j--] = arr[low];//无论是0还是非0元素都可以
//            if (!arr[low])
//            {
//                arr[j--] = arr[low];//无论是0
//            }
//            low--;
//        }
//    }
//};


//方法6
//class Solution 
//{
//public:
//    void duplicateZeros(vector<int>& arr) 
//    {
//        int cur = 0;
//        int dest = -1;
//        int flag1 = 0;
//        int flag2 = 0;
//        int n = arr.size();
//        // 1, 0, 2, 3, 0, 4, 5, 0
//        while (dest < n) 
//        {
//            if (dest + 1 >= n) 
//            {
//                flag2 = 1;
//                break;
//            }
//            if (arr[cur] == 0) 
//            {
//                // int temp = ;
//                if (dest + 2 >= arr.size()) 
//                {
//                    dest += 1;
//                    flag1 = 1;
//                }
//                else 
//                {
//                    dest += 2;
//                }
//            }
//            else 
//            {
//                dest += 1;
//            }
//            if (dest < n) 
//            {
//                cur += 1;
//            }
//        }
//        while (cur > 0) 
//        {
//            cur--;
//            if (flag2 == 1) 
//            {
//                flag2 = 0;
//            }
//            else 
//            {
//                dest--;
//            }
//            if (arr[cur] == 0) 
//            {
//                if (flag1 == 1) 
//                {
//                    arr[dest] = 0;
//                    flag1 = 0;
//                }
//                else 
//                {
//                    arr[dest] = 0;
//                    dest--;
//                    arr[dest] = 0;
//                }
//            }
//            else 
//            {
//                arr[dest] = arr[cur];
//            }
//        }
//    }
//};


//方法7
//额外空间
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int left = 0;
//        int n = arr.size();
//        vector<int> arr1;      // 记录非0元素
//        vector<int> arr2(arr); // 拷贝
//        arr1.resize(n);
//        int i = 0;
//        for (left = 0; left < n; left++) {
//            if (arr[left] != 0) {
//                arr1[i++] = arr[left];
//            }
//        }
//        i = 0;
//        int j = 0;
//        for (left = 0; left < n; left++) {
//            if (arr2[j] != 0) {
//                arr[left] = arr1[i++];
//            }
//            else {
//                arr[left] = 0;
//                if (left + 1 < n) {
//                    left++;
//                    arr[left] = 0;
//                }
//            }
//            j++;
//        }
//    }
//};


//第202题
//快乐数
//https://leetcode.cn/problems/happy-number/
//方法1
//#include<math.h>
//class Solution 
//{
//public:
//    bool isHappy(int n) 
//    {
//        int count = 100;
//        int flag = 1;
//        while (count)
//        {
//            string str = to_string(n);
//            int sum = 0;
//            for (auto e : str)
//            {
//                int temp = e - '0';
//                sum += pow(temp, 2);
//            }
//            n = sum;
//            if (n == 1)
//            {
//                flag = 0;
//                break;
//            }
//            count--;
//        }
//        if (flag == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//};


//方法2
//class Solution {
//public:
//    int SquareSum(int n) 
//    {
//        int sum = 0;
//        while (n > 0)
//        {
//            int t = n % 10;
//            sum += t * t;
//            n = n / 10;
//        }
//        return sum;
//    }
//
//    bool isHappy(int n) 
//    {
//        int slow = n, fast = n;
//        do {
//            slow = SquareSum(slow);
//            fast = SquareSum(fast);
//            fast = SquareSum(fast);
//        } while (slow != fast);
//        return slow == 1;
//    }
//};


//第11题
//盛最多水的容器
//https://leetcode.cn/problems/container-with-most-water/description/
//方法1
//class Solution 
//{
//public:
//    int maxArea(vector<int>& height) 
//    {
//        int left = 0;
//        int n = height.size();
//        int right = n - 1;
//        int area = 0;
//        int maxArea = 0;
//        while (left < right)
//        {
//            area = (right - left) * min(height[left], height[right]);
//            maxArea = max(area, maxArea);
//            if (height[left] < height[right])
//            {
//                left++;
//            }
//            else
//            {
//                right--;
//            }
//        }
//        return maxArea;
//    }
//};


//第611题
//有效的三角形个数
//https://leetcode.cn/problems/valid-triangle-number/
//方法1
//判断3次
//方法2
//已知三条边的大小顺序,只需让两条最短边大于第3条边s即可
//class Solution 
//{
//public:
//    int triangleNumber(vector<int>& nums) 
//    {
//        int k = 0;
//        int count = 0;
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < n - 2; i++)
//        {
//            if (nums[i] == 0)
//            {
//                continue;
//            }
//            k = i + 2;
//            for (int j = i + 1; j < n - 1; j++)
//            {
//                while (k<n && nums[i] + nums[j]>nums[k])
//                {
//                    k++;
//                }
//                count += k - 1 - j;
//            }
//        }
//        return count;
//    }
//};


//方法2
//排序+双指针
//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        //排序降低时间复杂度
//        sort(nums.begin(), nums.end());
//        //双指针
//        int ret = 0;
//        int n = nums.size();
//        for (int i = n - 1; i >= 2; i--)
//        {
//            //利用双指针快速统计符合要求的三元组的个数
//            int left = 0;
//            int right = i - 1;
//            while (left < right)
//            {
//                if (nums[left] + nums[right] > nums[i])
//                {
//                    ret += right - left;
//                    right--;
//                }
//                else
//                {
//                    left++;
//                }
//            }
//        }
//        return ret;
//    }
//};


//三数之和
//第15题
//https://leetcode.cn/problems/3sum/description/
//方法1
//class Solution 
//{
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) 
//    {
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end()); // 排序，方便去重和双指针操作
//        int n = nums.size();
//        for (int i = 0; i < n; i++) 
//        {
//            // 跳过i的重复元素
//            if (i > 0 && nums[i] == nums[i - 1])
//            {
//                continue;
//            }
//            int left = i + 1; // 左指针
//            int right = n - 1; // 右指针
//            while (left < right) 
//            {
//                int sum = nums[i] + nums[left] + nums[right];
//                if (sum == 0) 
//                {
//                    // 找到符合条件的三元组
//                    result.push_back({ nums[i], nums[left], nums[right] });
//                    // 跳过left的重复元素
//                    while (left < right && nums[left] == nums[left + 1])
//                    {
//                        left++;
//                    }
//                    // 跳过right的重复元素
//                    while (left < right && nums[right] == nums[right - 1])
//                    {
//                        right--;
//                    }
//                    // 移动指针继续寻找
//                    left++;
//                    right--;
//                }
//                else if (sum < 0) 
//                {
//                    // 和太小，左指针右移增大和
//                    left++;
//                }
//                else 
//                {
//                    // 和太大，右指针左移减小和
//                    right--;
//                }
//            }
//        }
//        return result;
//    }
//};


//方法2
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> result;
//        // 排序
//        sort(nums.begin(), nums.end());
//        // 双指针
//        int n = nums.size();
//        for (size_t i = 0; i < n - 2;) {
//            if (nums[i] > 0) {
//                // 固定的第1个数大于0,所有的数字之和一定大于0
//                break;
//            }
//            int left = i + 1;
//            int right = n - 1;
//            int target = -nums[i];
//            while (left < right) {
//                int sum = nums[left] + nums[right];
//                if (sum > target) {
//                    right--;
//                }
//                else if (sum < target) {
//                    left++;
//                }
//                else {
//                    result.push_back({ nums[i], nums[left], nums[right] });
//                    left++;
//                    right--;
//                    while (left < right && nums[left] == nums[left - 1]) {
//                        left++;
//                    }
//                    while (left < right && nums[right] == nums[right + 1]) {
//                        right--;
//                    }
//                }
//            }
//            i++;
//            while (i < n && i>0 && nums[i] == nums[i - 1])
//            {
//                i++;
//            }
//        }
//        return result;
//    }
//};


//四数之和
//方法1
//排序+双指针(类似于三数之和)
//class Solution 
//{
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        vector<vector<int>> vec;
//        // 1. 排序
//        sort(nums.begin(), nums.end());
//
//        // 利用双指针解决问题
//        int n = nums.size();
//        for (int i = 0; i < n - 3;) {
//
//            for (int j = i + 1; j < n - 2;) {
//                int left = j + 1;
//                int right = n - 1;
//                long long aim = (long long)target - nums[i] - nums[j];
//                while (left < right) {
//                    int sum = nums[left] + nums[right];
//                    if (sum < aim) {
//                        left++;
//                    }
//                    else if (sum > aim) {
//                        right--;
//                    }
//                    else {
//                        vec.push_back(
//                            { nums[i], nums[j], nums[left++], nums[right--] });
//                        while (left < right && nums[left] == nums[left - 1]) {
//                            left++;
//                        }
//                        while (left < right && nums[right] == nums[right + 1]) {
//                            right--;
//                        }
//                    }
//                }
//                j++;
//                while (j < n - 2 && nums[j] == nums[j - 1]) {
//                    j++;
//                }
//            }
//            i++;
//            while (i < n - 3 && nums[i] == nums[i - 1]) {
//                i++;
//            }
//        }
//        return vec;
//    }
//};


//方法2
//极致优化
//class Solution 
//{
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) 
// {
//        vector<vector<int>> result;
//        int n = nums.size();
//        // 边界条件：数组长度不足4时直接返回空
//        if (n < 4) return result;
//
//        // 排序是双指针的前提
//        sort(nums.begin(), nums.end());
//
//        // 第一层循环：固定第一个数
//        for (int i = 0; i <= n - 4; ++i) {
//            // 去重：跳过与前一个数重复的情况
//            if (i > 0 && nums[i] == nums[i - 1]) continue;
//
//            // 剪枝1：当前i的最小四数和 > target，后续更大，直接break
//            long long min_sum_i = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
//            if (min_sum_i > target) break;
//
//            // 剪枝2：当前i的最大四数和 < target，当前i无解，continue
//            long long max_sum_i = (long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1];
//            if (max_sum_i < target) continue;
//
//            // 第二层循环：固定第二个数
//            for (int j = i + 1; j <= n - 3; ++j) {
//                // 去重：跳过与前一个数重复的情况（注意j > i+1）
//                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//
//                // 剪枝3：当前i+j的最小四数和 > target，break
//                long long min_sum_j = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
//                if (min_sum_j > target) break;
//
//                // 剪枝4：当前i+j的最大四数和 < target，continue
//                long long max_sum_j = (long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1];
//                if (max_sum_j < target) continue;
//
//                // 双指针：第三、第四个数
//                int left = j + 1, right = n - 1;
//                while (left < right) {
//                    // 用long long避免int溢出
//                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
//
//                    if (sum == target) {
//                        // 找到符合条件的四元组
//                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
//
//                        // 去重：跳过left重复值
//                        while (left < right && nums[left] == nums[left + 1]) ++left;
//                        // 去重：跳过right重复值
//                        while (left < right && nums[right] == nums[right - 1]) --right;
//
//                        // 移动指针找下一组
//                        ++left;
//                        --right;
//                    }
//                    else if (sum < target) {
//                        // 和太小，左指针右移增大和
//                        ++left;
//                    }
//                    else {
//                        // 和太大，右指针左移减小和
//                        --right;
//                    }
//                }
//            }
//        }
//        return result;
//    }
//};