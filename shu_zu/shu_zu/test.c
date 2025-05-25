#define _CRT_SECURE_NO_WARNINGS 1 
//第1题
//两数之和
//给定一个整数数组nums和一个整数目标值target,
//请你在该数组中找出和为目标值target的那两个整数,并返回它们的数组下标
//你可以假设每种输入只会对应一个答案,并且你不能使用两次相同的元素。
//你可以按任意顺序返回答案。
//示例1:
//输入:nums = [2, 7, 11, 15], target = 9
//输出:[0, 1]
//解释:因为nums[0] + nums[1] == 9,返回[0, 1]。
//示例2:
//输入:nums = [3, 2, 4], target = 6
//输出:[1, 2]
//示例3:
//输入:nums = [3, 3], target = 6
//输出:[0, 1]
//提示:
//2 <= nums.length <= 104
//- 109 <= nums[i] <= 109
//- 109 <= target <= 109
//只会存在一个有效答案
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    int i = 0;
//    for (i = 0;i < numsSize;i++)
//    {
//        int j = 0;
//        for (j = i + 1;j < numsSize;j++)
//        {
//            if (nums[j] + nums[i] == target)
//            {
//                int* result = (int*)malloc(sizeof(int) * 2);
//                if (result == NULL)
//                {
//                    *returnSize = 0;
//                    return returnSize;
//                }
//                result[0] = i;
//                result[1] = j;
//                *returnSize = 2;
//                return result;
//            }
//        }
//    }
//    *returnSize = 0;
//    return NULL;
//}


//方法2
//双指针
//typedef struct nums {
//    int value;
//    int index;
//}element;
//int compare(const void* num1, const void* num2)
//{
//    return ((element*)num1)->value - ((element*)num2)->value;
//}
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    //对数组排序
//    element* Element = (element*)malloc(sizeof(element) * numsSize);
//    int i = 0;
//    for (i = 0;i < numsSize;i++)
//    {
//        Element[i].value = nums[i];
//        Element[i].index = i;
//    }
//    qsort(Element, numsSize, sizeof(Element), compare);
//    //使用双指针
//    int left = 0;
//    int right = numsSize - 1;
//    int* result = (int*)malloc(sizeof(int) * 2);
//    if (result == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    while (left < right)
//    {
//        int sum = Element[left].value + Element[right].value;
//        if (sum == target)
//        {
//            result[0] = Element[left].index;
//            result[1] = Element[right].index;
//            *returnSize = 2;
//            free(Element);
//            return result;
//        }
//        else if (sum < target)
//        {
//            left++;
//        }
//        else {
//            right--;
//        }
//    }
//    free(Element);
//    *returnSize = 0;
//    return NULL;
//}


//第3题
//无重复字符的最长子串
//提示
//给定一个字符串s,请你找出其中不含有重复字符的最长子串的长度
//示例1:
//输入:s = "abcabcbb"
//输出:3
//解释:因为无重复字符的最长子串是"abc",所以其长度为3
//示例2:
//输入:s="bbbbb"
//输出:1
//解释:因为无重复字符的最长子串是"b",所以其长度为1
//示例3:
//输入:s = "pwwkew"
//输出:3
//解释:因为无重复字符的最长子串是"wke",所以其长度为3。
//请注意,你的答案必须是子串的长度,"pwke"是一个子序列，不是子串。
//提示：
//0 <= s.length <= 5 * 104
//s由英文字母、数字、符号和空格组成
#include<stdio.h>
#include<stdlib.h>
typedef struct lettle {
    char c;
    int index;
} lettle;
int compare(const void* a, const void* b) {
    return ((lettle*)a)->c - ((lettle*)b)->c;
}
int lengthOfLongestSubstring(char* s) {
    if (strlen(s) == 1) {
        return 1;
    }
    lettle* let = (lettle*)malloc(strlen(s) * sizeof(lettle));
    int i = 0;
    for (i = 0; i < strlen(s); i++) {
        let[i].index = i;
        let[i].c = s[i];
    }
    int left = 0;
    int right = 1;
    int count = 1;
    int temp = strlen(s);
    int temp1 = 0;
    while (count >= 1) {
        lettle* tmp = (lettle*)malloc(temp * sizeof(lettle));
        int temp2 = 0;
        for (i = temp1; i < temp; i++) {
            tmp[temp2++].c = s[i];
        }
        qsort(let, strlen(s), sizeof(lettle), compare);
        while (right < temp)
        {
            char num1 = tmp[left].c;
            char num2 = tmp[right].c;
            if (num2 != num1) {
                left++;
                let[left].c = let[right].c;
                count++;
            }
            else {
                right++;
            }
        }
        if (temp1 + temp < strlen(s))
        {
            temp1++;
        }
        else {
            temp1 = 0;
        }
        if (left != count && temp1 + temp <= strlen(s))
        {
            temp--;
        }
        else {
            return count;
        }
    }
    return 1;
}


//#include <stdbool.h>
//#include <stdio.h>
//#include <stdlib.h>
//bool isPalindrome(int x) 
//{
//    if (x < 0) return false;
//    if (x < 10) return true;
//    long long original = x;
//    long long reversed = 0;
//    while (x > 0) {
//        reversed = reversed * 10 + x % 10;
//        x /= 10;
//    }
//    return original == reversed;
//}


//第26题
//删除有序数组中的重复项
//给你一个非严格递增排列的数组nums,请你原地删除重复出现的元素,使每个元素只出现一次
//返回删除后数组的新长度。元素的相对顺序应该保持一致。
//然后返回nums中唯一元素的个数
//考虑nums的唯一元素的数量为k,更改数组nums,
//使nums的前k个元素包含唯一元素,并按照它们最初在nums中出现的顺序排列。
//nums的其余元素与nums的大小不重要,返回k。
//示例1:
//输入:nums = [1, 1, 2]
//输出:2,nums = [1, 2, _]
//解释:函数应该返回新的长度2,并且原数组nums的前两个元素被修改为1,2。
//不需要考虑数组中超出新长度后面的元素。
//示例2:
//输入:nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//输出:5,nums = [0, 1, 2, 3, 4]
//解释:函数应该返回新的长度5,并且原数组nums的前五个元素被修改为0,1,2,3,4。
//不需要考虑数组中超出新长度后面的元素。
//提示:
//1 <= nums.length <= 3 * 104
//- 104 <= nums[i] <= 104
//nums已按非严格递增排列
//方法1
//int removeDuplicates(int* nums, int numsSize)
//{
//    int left = 0;
//    int right = left + 1;
//    while (right < numsSize)
//    {
//        if (nums[left] == nums[right])
//        {
//            right++;
//        }
//        else
//        {
//            left++;
//            nums[left] = nums[right];
//        }
//    }
//    return left + 1;
//}


//方法2
//这道题目的要求是对给定的有序数组nums删除重复元素,
//在删除重复元素之后,每个元素只出现一次,并返回新的长度,上述操作必须通过原地修改数组的方法,
//使用O(1)的空间复杂度完成
//由于给定的数组nums是有序的,因此对于任意i<j,如果nums[i]=nums[j],
//则对任意i≤k≤j,必有nums[i] = nums[k] = nums[j],即相等的元素在数组中的下标一定是连续的。
//利用数组有序的特点,可以通过双指针的方法删除重复元素。
//如果数组nums的长度为0,则数组不包含任何元素,因此返回0。
//当数组nums的长度大于0时,数组中至少包含一个元素,在删除重复元素之后也至少剩下一个元素,
//因此nums[0]保持原状即可,从下标1开始删除重复元素。
//定义两个指针fast和slow分别为快指针和慢指针,快指针表示遍历数组到达的下标位置,
//慢指针表示下一个不同元素要填入的下标位置,初始时两个指针都指向下标1。
//假设数组nums的长度为n。将快指针fast依次遍历从1到n−1的每个位置,对于每个位置,
//如果nums[fast] = nums[fast−1],说明nums[fast]和之前的元素都不同,
//因此将nums[fast]的值复制到nums[slow],然后将slow的值加1,即指向下一个位置。
//遍历结束之后,从nums[0]到nums[slow−1]的每个元素都不相同且包含原数组中的每个不同的元素,
//因此新的长度即为 slow,返回slow即可。
//int removeDuplicates(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//    {
//        return 0;
//    }
//    int left = 1;
//    int right = 1;
//    while (right < numsSize)
//    {
//        if (nums[right - 1] != nums[right])
//        {
//            nums[left] = nums[right];
//            left++;
//        }
//        right++;
//    }
//    return left;
//}


//第27题
//给你一个数组nums和一个值val,你需要原地移除所有数值等于val的元素,元素的顺序可能发生改变。
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


struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode* STLFind(struct ListNode* head, int x)
{
    struct ListNode* cur = head;
    while (cur != NULL)
    {
        if (cur->val == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    while (cur != NULL)
    {
        struct ListNode* tmp = STLFind(cur, val);
        if (head == tmp)
        {
            head = head->next;
            free(head);
        }
        else
        {
            struct ListNode* temp = head;
            while (temp->next != tmp)
            {
                temp = temp->next;
            }
            temp = tmp->next;
            free(tmp);
        }
        cur = cur->next;
    }
    return head;
}