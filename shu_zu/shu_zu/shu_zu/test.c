#define _CRT_SECURE_NO_WARNINGS 1 

//第27题
//给你一个数组nums和一个值 val,你需要原地移除所有数值等于val的元素,元素的顺序可能发生改变。
//然后返回nums中与val不同的元素的数量。
//假设nums中不等于val的元素数量为k,要通过此题,您需要执行以下操作:
//更改nums数组,使nums的前k个元素包含不等于val的元素。
//nums的其余元素和nums的大小并不重要,返回k。
//评测机将使用以下代码测试您的解决方案：
//int[] nums = [...]; //输入数组
//int val = ...; //要移除的值
//int[] expectedNums = [...]; //长度正确的预期答案
////它以不等于val的值排序
//int k = removeElement(nums, val); //调用你的实现
//assert k == expectedNums.length;
//sort(nums, 0, k); //排序nums的前k个元素
//for (int i = 0; i < actualLength; i++) 
//{
//    assert nums[i] == expectedNums[i];
//}
//如果所有的断言都通过,你的解决方案将会通过。
//示例 1:
//输入:nums = [3, 2, 2, 3], val = 3
//输出:2,nums = [2, 2, _, _]
//解释:你的函数函数应该返回k = 2,并且nums中的前两个元素均为2。
//你在返回的k个元素之外留下了什么并不重要(因此它们并不计入评测)。
//示例 2:
//输入:nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//输出:5, nums = [0, 1, 4, 0, 3, _, _, _]
//解释:你的函数应该返回 k = 5,并且 nums 中的前五个元素为 0, 0, 1, 3, 4。
//注意这五个元素可以任意顺序返回。
//你在返回的k个元素之外留下了什么并不重要(因此它们并不计入评测)
//提示:
//0 <= nums.length <= 100
//0 <= nums[i] <= 50
//0 <= val <= 100
//方法1
//#include <stdio.h>
//#define element 100
//int removeElement(int* nums, int numsSize, int val) 
//{
//    int i = 0;
//    int count = 0;
//    int temp1 = numsSize;
//    while (i < temp1) 
//    {
//        if (nums[i] == val) 
//        {
//            int temp = i;
//            while (temp < numsSize - 1) 
//            {
//                nums[temp] = nums[temp + 1];
//                temp++;
//            }
//            count++;
//            temp1--;
//        }
//        else 
//        {
//            i++;
//        }
//    }
//    printf("%d,", numsSize - count);
//    for (i = 0; i < numsSize - count; i++) 
//    {
//        if (i == 0)
//        {
//            printf("nums = [");
//        }
//        printf("%d", nums[i]);
//        if (i != numsSize - count - 1)
//        {
//            printf(",");
//        }
//        if (i == numsSize-count-1)
//        {
//            printf("]");
//        }
//    }
//    return numsSize - count;
//}
//int main()
//{
//    int num[element] = { 0,1,2,2,3,0,4,2 };
//    int val = 2;
//    removeElement(num, 8, val);
//    return 0;
//}


//方法2
//双指针
//由于题目要求删除数组中等于val的元素, 因此输出数组的长度一定小于等于输入数组的长度,
//我们可以把输出的数组直接写在输入数组上。
//可以使用双指针 : 右指针right指向当前将要处理的元素, 左指针left指向下一个将要赋值的位置
//如果右指针指向的元素不等于val, 它一定是输出数组的一个元素,
//我们就将右指针指向的元素复制到左指针位置,然后将左右指针同时右移;
//如果右指针指向的元素等于val,它不能在输出数组里,此时左指针不动,右指针右移一位
//整个过程保持不变的性质是:区间[0,left)中的元素都不等于val。
//当左右指针遍历完输入数组以后,left的值就是输出数组的长度
//这样的算法在最坏情况下(输入数组中没有元素等于val),左右指针各遍历了数组一次
// 复杂度分析
//时间复杂度:O(n),其中n为序列的长度,我们只需要遍历该序列至多两次
//空间复杂度:O(1),我们只需要常数的空间保存若干变量。
//int removeElement(int* nums, int numsSize, int val) 
//{
//    int left = 0;
//    for (int right = 0; right < numsSize; right++) 
//    {
//        if (nums[right] != val) 
//        {
//            nums[left] = nums[right];
//            left++;
//        }
//    }
//    return left;
//}


//方法3
//双指针优化
//如果要移除的元素恰好在数组的开头,例如序列[1,2,3,4,5]
//当val为1时,我们需要把每一个元素都左移一位。
//注意到题目中说:元素的顺序可以改变,实际上我们可以直接将最后一个元素5移动到序列开头,
//取代元素1,得到序列[5,2,3,4],同样满足题目要求。
//这个优化在序列中val元素的数量较少时非常有效。
//我们依然使用双指针,两个指针初始时分别位于数组的首尾,向中间移动遍历该序列
//如果左指针left指向的元素等于val,此时将右指针right指向的元素复制到左指针left的位置,
//然后右指针right左移一位。如果赋值过来的元素恰好也等于val,
//可以继续把右指针right指向的元素的值赋值过来
//(左指针left指向的等于val的元素的位置继续被覆盖),直到左指针指向的元素的值不等于val为止。
//当左指针left和右指针right重合的时候,左右指针遍历完数组中所有的元素。
//这样的方法两个指针在最坏的情况下合起来只遍历了数组一次。
//与方法一不同的是,方法二避免了需要保留的元素的重复赋值操作。
//int removeElement(int* nums, int numsSize, int val) 
//{
//    int left = 0, right = numsSize;
//    while (left < right) 
//    {
//        if (nums[left] == val) 
//        {
//            nums[left] = nums[right - 1];
//            right--;
//        }
//        else 
//        {
//            left++;
//        }
//    }
//    return left;
//}
