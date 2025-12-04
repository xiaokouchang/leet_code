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


//1089
//https://leetcode.cn/problems/duplicate-zeros/
//方法1
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
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
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
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


//方法3
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int cur = 0;
//        int dest = -1;
//        int flag1 = 0;
//        int flag2 = 0;
//        int n = arr.size();
//        // 1, 0, 2, 3, 0, 4, 5, 0
//        while (dest < n) {
//            if (dest + 1 >= n) {
//                flag2 = 1;
//                break;
//            }
//            if (arr[cur] == 0) {
//                // int temp = ;
//                if (dest + 2 >= arr.size()) {
//                    dest += 1;
//                    flag1 = 1;
//                }
//                else {
//                    dest += 2;
//                }
//            }
//            else {
//                dest += 1;
//            }
//            if (dest < n) {
//                cur += 1;
//            }
//        }
//        while (cur > 0) {
//            cur--;
//            if (flag2 == 1) {
//                flag2 = 0;
//            }
//            else {
//                dest--;
//            }
//            if (arr[cur] == 0) {
//                if (flag1 == 1) {
//                    arr[dest] = 0;
//                    flag1 = 0;
//                }
//                else {
//                    arr[dest] = 0;
//                    dest--;
//                    arr[dest] = 0;
//                }
//            }
//            else {
//                arr[dest] = arr[cur];
//            }
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
