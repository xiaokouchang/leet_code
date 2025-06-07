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
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct lettle {
//    char c;
//    int index;
//} lettle;
//int compare(const void* a, const void* b) {
//    return ((lettle*)a)->c - ((lettle*)b)->c;
//}
//int lengthOfLongestSubstring(char* s) {
//    if (strlen(s) == 1) {
//        return 1;
//    }
//    lettle* let = (lettle*)malloc(strlen(s) * sizeof(lettle));
//    int i = 0;
//    for (i = 0; i < strlen(s); i++) {
//        let[i].index = i;
//        let[i].c = s[i];
//    }
//    int left = 0;
//    int right = 1;
//    int count = 1;
//    int temp = strlen(s);
//    int temp1 = 0;
//    while (count >= 1) {
//        lettle* tmp = (lettle*)malloc(temp * sizeof(lettle));
//        int temp2 = 0;
//        for (i = temp1; i < temp; i++) {
//            tmp[temp2++].c = s[i];
//        }
//        qsort(let, strlen(s), sizeof(lettle), compare);
//        while (right < temp)
//        {
//            char num1 = tmp[left].c;
//            char num2 = tmp[right].c;
//            if (num2 != num1) {
//                left++;
//                let[left].c = let[right].c;
//                count++;
//            }
//            else {
//                right++;
//            }
//        }
//        if (temp1 + temp < strlen(s))
//        {
//            temp1++;
//        }
//        else {
//            temp1 = 0;
//        }
//        if (left != count && temp1 + temp <= strlen(s))
//        {
//            temp--;
//        }
//        else {
//            return count;
//        }
//    }
//    return 1;
//}


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


//第21题 --- 合并两个有序链表
//将两个升序链表合并为一个新的升序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。
//示例1:
//输入:l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出:[1, 1, 2, 3, 4, 4]
//示例2:
//输入:l1 = [],l2 = []
//输出:[]
//示例3:
//输入:l1 = [],l2 = [0]
//输出:[0]
//提示:
//两个链表的节点数目范围是[0, 50]
//-100<=Node.val<=100
//l1和l2均按非递减顺序排列
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode dummy = { 0 };
//    struct ListNode* tail = &dummy;
//    while (list1 != NULL && list2 != NULL) {
//        if (list1->val <= list2->val) {
//            tail->next = list1;
//            list1 = list1->next;
//        }
//        else {
//            tail->next = list2;
//            list2 = list2->next;
//        }
//        tail = tail->next;
//    }
//    if (list1 != NULL) {
//        tail->next = list1;
//    }
//    else {
//        tail->next = list2;
//    }
//    return dummy.next;
//}


//方法2
//#include <stdio.h>
//#include <stdlib.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* cur1 = list1;
//    struct ListNode* cur2 = list2;
//    struct ListNode* head = NULL;
//    struct ListNode* tail = NULL;
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//    while (cur1 && cur2) {
//        if (cur1->val < cur2->val) {
//            if (head == NULL) {
//                head = tail = cur1;
//            }
//            else {
//                tail->next = cur1;
//                tail = tail->next;
//            }
//            cur1 = cur1->next;
//        }
//        else {
//            if (head == NULL) {
//                head = tail = cur2;
//            }
//            else {
//                tail->next = cur2;
//                tail = tail->next;
//            }
//            cur2 = cur2->next;
//        }
//    }
//    if (cur1) {
//        tail->next = cur1;
//    }
//    else {
//        tail->next = cur2;
//    }
//    return head;
//}
//struct ListNode* test1()
//{
//    struct ListNode* a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    a1->val = 1;
//    a2->val = 2;
//    a3->val = 4;
//    a1->next = a2;
//    a2->next = a3;
//    a3->next = NULL;
//    return a1;
//}
//struct ListNode* test2()
//{
//    struct ListNode* b1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* b2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* b3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    b1->val = 2;
//    b2->val = 3;
//    b3->val = 4;
//    b1->next = b2;
//    b2->next = b3;
//    b3->next = NULL;
//    return b1;
//}
//int main()
//{
//    struct ListNode* n1 = test1();
//    struct ListNode* n2 = test2();
//    struct ListNode* cur = mergeTwoLists(n1, n2);
//    while (cur)
//    {
//        printf("%d->", cur->val);
//        cur = cur->next;
//    }
//    printf("NULL\n");
//    return 0;
//}


//方法3
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
//{
//    struct ListNode* cur1 = list1;
//    struct ListNode* cur2 = list2;
//    struct ListNode* guard = NULL;
//    struct ListNode* tail = NULL;
//    //带哨兵位的头结点
//    guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    tail->next = NULL;
//    while (cur1 && cur2) 
//    {
//        if (cur1->val < cur2->val) 
//        {
//            tail->next = cur1;
//            tail = tail->next;
//            cur1 = cur1->next;
//        }
//        else 
//        {
//            tail->next = cur2;
//            tail = tail->next;
//            cur2 = cur2->next;
//        }
//    }
//    if (cur1) 
//    {
//        tail->next = cur1;
//    }
//    else 
//    {
//        tail->next = cur2;
//    }
//    struct ListNode* head = guard->next;
//    free(guard);
//    return head;
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



//https://leetcode.cn/problems/copy-list-with-random-pointer/description/
//带环链表不能遍历



//第160题 --- 相交链表
//https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
//给你两个单链表的头节点headA和headB,请你找出并返回两个单链表相交的起始节点。
//如果两个链表不存在相交节点,返回null。
//图示两个链表在节点 c1 开始相交:
//题目数据保证整个链式结构中不存在环。
//注意,函数返回结果后,链表必须保持其原始结构。
//自定义评测:
//评测系统的输入如下(你设计的程序不适用此输入):
//intersectVal-相交的起始节点的值。如果不存在相交节点，这一值为 0
//listA-第一个链表
//listB-第二个链表
//skipA-在listA中(从头节点开始)跳到交叉节点的节点数
//skipB-在listB中(从头节点开始)跳到交叉节点的节点数
//评测系统将根据这些输入创建链式数据结构,并将两个头节点headA和headB传递给你的程序。
//如果程序能够正确返回相交节点,那么你的解决方案将被视作正确答案。
//示例1:
//输入:intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 6, 1, 8, 4, 5], skipA = 2, skipB = 3
//输出 : Intersected at '8'
//解释 : 相交节点的值为8(注意, 如果两个链表相交则不能为0)。
//从各自的表头开始算起, 链表A为[4, 1, 8, 4, 5], 链表B为[5, 6, 1, 8, 4, 5]。
//在A中, 相交节点前有2个节点;在B中, 相交节点前有3个节点。
//请注意相交节点的值不为1,因为在链表A和链表B之中值为1的节点(A中第二个节点和B中第三个节点)是不同的节点。
//换句话说,它们在内存中指向两个不同的位置,而链表A和链表B中值为8的节点(A中第三个节点,B中第四个节点)
//在内存中指向相同的位置。
//示例2:
//输入:intersectVal = 2, listA = [1, 9, 1, 2, 4], listB = [3, 2, 4], skipA = 3, skipB = 1
//输出 : Intersected at '2'
//解释 : 相交节点的值为2(注意, 如果两个链表相交则不能为0)。
//从各自的表头开始算起, 链表A为[1, 9, 1, 2, 4], 链表 B 为[3, 2, 4]。
//在A中,相交节点前有3个节点; 在B中, 相交节点前有1个节点。
//示例3:
//输入:intersectVal = 0, listA = [2, 6, 4], listB = [1, 5], skipA = 3, skipB = 2
//输出:No intersection
//解释:从各自的表头开始算起,链表A为[2, 6, 4],链表B为[1, 5]。
//由于这两个链表不相交,所以intersectVal必须为0,而skipA和skipB可以是任意值
//这两个链表不相交,因此返回null。
//提示:
//listA中节点数目为m
//listB中节点数目为n
//1 <= m, n <= 3 * 104
//1 <= Node.val <= 105
//0 <= skipA <= m
//0 <= skipB <= n
//如果listA和listB没有交点,intersectVal为0
//如果listA和listB有交点,intersectVal == listA[skipA] == listB[skipB]
//进阶:你能否设计一个时间复杂度O(m+n),仅用O(1)内存的解决方案?
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    int lenA = 1;
//    int lenB = 1;
//    while (tailA->next) {
//        tailA = tailA->next;
//        lenA++;
//    }
//    while (tailB->next) {
//        tailB = tailB->next;
//        lenB++;
//    }
//    if (tailA != tailB) {
//        return NULL;
//    }
//    int gap = abs(lenA - lenB);
//    struct ListNode* LongList = headA;
//    struct ListNode* shortList = headB;
//    if (lenA < lenB) {
//        LongList = headB;
//        shortList = headA;
//    }
//    while (gap--) {
//        LongList = LongList->next;
//    }
//    while (LongList != shortList) {
//        LongList = LongList->next;
//        shortList = shortList->next;
//    }
//    return LongList;
//}


//第203题
//给你一个链表的头节点head和一个整数val,请你删除链表中所有满足Node.val==val的节点,并返回新的头节点
//示例1:
//输入:head = [1, 2, 6, 3, 4, 5, 6], val = 6
//输出:[1, 2, 3, 4, 5]
//示例2:
//输入:head = [], val = 1
//输出:[]
//示例3:
//输入:head = [7, 7, 7, 7], val = 7
//输出:[]
//提示:
//列表中的节点数目在范围[0, 104]内
//1 <= Node.val <= 50
//0 <= val <= 50
//方法1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//typedef struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//}ListNode;
//void STLPushBack(ListNode** phead, int val);
//ListNode* STLGiveNode(ListNode** phead, int val);
//
//ListNode* STLGiveNode(ListNode** phead, int val)
//{
//    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//    if (newnode == NULL)
//    {
//        perror("STLGiveNode");
//        return;
//    }
//    newnode->val = val;
//    newnode->next = NULL;
//    return newnode;
//}
//
//void STLPushBack(ListNode** phead, int val)
//{
//    ListNode* newnode = STLGiveNode(phead, val);
//    if (*phead == NULL)
//    {
//        *phead = newnode;
//    }
//    else
//    {
//        ListNode* cur = *phead;
//        while (cur->next != NULL)
//        {
//            cur = cur->next;
//        }
//        cur->next = newnode;
//    }
//}
//ListNode* removeElements(struct ListNode** head, int val) 
//{
//    while (*head != NULL && (*head)->val == val)
//    {
//        ListNode* tmp = *head;
//        *head = (*head)->next;
//        free(tmp);
//    }
//    ListNode* temp = *head;
//    while (temp != NULL && temp->next != NULL)
//    {
//        if (temp->next->val == val)
//        {
//            ListNode* cur = temp->next;
//            temp->next = cur->next;
//            free(cur);
//        }
//        else
//        {
//            temp = temp->next;
//        }
//    }
//}
//void STLPrint(struct ListNode* head)
//{
//    ListNode* cur = head;
//    while (cur != NULL)
//    {
//        printf("%d->", cur->val);
//        cur = cur->next;
//    }
//    printf("NULL\n");
//}
//int main()
//{
//    ListNode* plist = NULL;
//    STLPushBack(&plist, 1);
//    STLPushBack(&plist, 2);
//    STLPushBack(&plist, 2);
//    STLPushBack(&plist, 4);
//    removeElements(&plist, 4);
//    STLPrint(plist);
//    return 0;
//}


//方法2
//递归
//链表的定义具有递归的性质,因此链表题目常可以用递归的方法求解
//这道题要求删除链表中所有节点值等于特定值的节点,可以用递归实现
//对于给定的链表,首先对除了头节点head以外的节点进行删除操作,然后判断head的节点值是否等于给定的val。
//如果head的节点值等于val,则head需要被删除,因此删除操作后的头节点为head.next;
//如果head的节点值不等于val,则head保留,因此删除操作后的头节点还是head。
//上述过程是一个递归的过程
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//typedef struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//}ListNode;
//ListNode* removeElements(struct ListNode* head, int val);
//ListNode* STLGiveNode(ListNode** phead, int val)
//{
//    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//    if (newnode == NULL)
//    {
//        perror("STLGiveNode");
//        return;
//    }
//    newnode->val = val;
//    newnode->next = NULL;
//    return newnode;
//}
//
//void STLPushBack(ListNode** phead, int val)
//{
//    ListNode* newnode = STLGiveNode(phead, val);
//    if (*phead == NULL)
//    {
//        *phead = newnode;
//    }
//    else
//    {
//        ListNode* cur = *phead;
//        while (cur->next != NULL)
//        {
//            cur = cur->next;
//        }
//        cur->next = newnode;
//    }
//}
//ListNode* removeElements(struct ListNode* head, int val) 
//{
//    if (head == NULL)
//    {
//        return head;
//    }
//    head->next = removeElements(head->next, val);
//    return head->val == val ? head->next : head;
//}
//void STLPrint(struct ListNode* head)
//{
//    ListNode* cur = head;
//    while (cur != NULL)
//    {
//        printf("%d->", cur->val);
//        cur = cur->next;
//    }
//    printf("NULL\n");
//}
//int main()
//{
//    ListNode* plist = NULL;
//    STLPushBack(&plist, 1);
//    STLPushBack(&plist, 2);
//    STLPushBack(&plist, 2);
//    STLPushBack(&plist, 4);
//    removeElements(plist, 4);
//    STLPrint(plist);
//    return 0;
//}


//方法3
//迭代
//也可以用迭代的方法删除链表中所有节点值等于特定值的节点。
//用temp表示当前节点。如果temp的下一个节点不为空且下一个节点的节点值等于给定的val,则需要删除下一个节点。
//删除下一个节点可以通过以下做法实现:
//temp.next = temp.next.next
//如果temp的下一个节点的节点值不等于给定的val,则保留下一个节点,将temp移动到下一个节点即可
//当temp的下一个节点为空时,链表遍历结束,此时所有节点值等于val的节点都被删除
//具体实现方面,由于链表的头节点head有可能需要被删除,因此创建哑节点dummyHead,
//令dummyHead.next = head,初始化temp = dummyHead,然后遍历链表进行删除操作。
//最终返回dummyHead.next即为删除操作后的头节点
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//}ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val) 
//{
//    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
//    dummyHead->next = head;
//    struct ListNode* temp = dummyHead;
//    while (temp->next != NULL) 
//    {
//        if (temp->next->val == val) 
//        {
//            temp->next = temp->next->next;
//        }
//        else 
//        {
//            temp = temp->next;
//        }
//    }
//    return dummyHead->next;
//}


//方法4---两个一前一后指针
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//struct ListNode* removeElements(struct ListNode* head, int val);
//struct ListNode* removeElements(struct ListNode* head, int val) 
//{
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = NULL;
//    while (cur)
//    {
//        if (cur->val != val)
//        {
//            //尾插
//            if (tail == NULL)
//            {
//                newhead = tail = cur;
//            }
//            else
//            {
//                tail->next = cur;
//                tail = tail->next;
//            }
//            cur = cur->next;
//        }
//        else
//        {
//            struct ListNode* next = cur->next;
//            free(cur);
//            cur = next;
//        }
//    }
//    return newhead;
//}
//int main()
//{
//    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    n1->val = 1;
//    n2->val = 2;
//    n3->val = 2;
//    n4->val = 4;
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = NULL;
//    struct ListNode* head = removeElements(n1, 2);
//    while (head)
//    {
//        printf("%d->", head->val);
//        head = head->next;
//    }
//    printf("NULL\n");
//    return 0;
//}


//方法5
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = NULL;
//    while (cur) {
//        if (cur->val != val) {
//            // 尾插
//            if (tail == NULL) {
//                newhead = tail = cur;
//            }
//            else {
//                tail->next = cur;
//                tail = tail->next;
//            }
//            cur = cur->next;
//        }
//        else {
//            struct ListNode* next = cur->next;
//            free(cur);
//            cur = next;
//        }
//    }
//    if (tail)
//    {
//        tail->next = NULL;
//    }
//    return newhead;
//}


//第876题 --- 链表的中间结点
//给你单链表的头结点head,请你找出并返回链表的中间结点
//如果有两个中间结点,则返回第二个中间结点
//示例1:
//输入:head = [1, 2, 3, 4, 5]
//输出:[3, 4, 5]
//解释:链表只有一个中间结点,值为3
//示例2:
//输入:head = [1, 2, 3, 4, 5, 6]
//输出:[4, 5, 6]
//解释:该链表有两个中间结点,值分别为3和4,返回第二个结点
//提示:
//链表的结点数范围是[1, 100]
//1 <= Node.val <= 100
//方法1 --- 两次遍历
//#include <stdio.h>
//#include <stdlib.h>
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* middleNode(struct ListNode* head) 
//{
//    struct ListNode* cur = head;
//    struct ListNode* prev = head;
//    int count = 0;
//    while (cur)
//    {
//        count++;
//        cur = cur->next;
//    }
//    count /= 2;
//    count++;
//    for (count;count > 1;count--)
//    {
//        prev = prev->next;
//    }
//    return prev;
//}


//方法2 --- 一次遍历(快慢指针)
//#include <stdio.h>
//#include <stdlib.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//struct ListNode* middleNode(struct ListNode* head) 
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}


//https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/description/
//返回倒数第k个节点
//实现一种算法,找出单向链表中倒数第k个节点。返回该节点的值
//注意:本题相对原题稍作改动
//示例:
//输入:1->2->3->4->5 和 k = 2
//输出:4
//说明:
//给定的k保证是有效的。
//方法1
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//int kthToLast(struct ListNode* head, int k) 
//{
//    struct ListNode* cur = head;
//    int count = 0;
//    while (cur)
//    {
//        count++;
//        cur = cur->next;
//    }
//    int i = 0;
//    cur = head;
//    while (i < count - k)
//    {
//        cur = cur->next;
//        i++;
//    }
//    return cur->val;
//}


//方法2
//fast先走k-1步然后fast和slow一起走,直到fast为空
//#include <stdio.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//int kthToLast(struct ListNode* head, int k)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    int x = k - 1;
//    while (x > 0)
//    {
//        fast = fast->next;
//        x--;
//    }
//    while (fast->next != NULL)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow->val;
//}


//方法3
//fast先走k步然后fast和slow一起走,直到fast->next为空
//#include <stdio.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//int kthToLast(struct ListNode* head, int k) 
//{
//    if (head == NULL)
//    {
//        return 0;
//    }
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (k--)
//    {
//        if (fast == NULL)
//        {
//            return 0;
//        }
//        fast = fast->next;
//    }
//    while (fast != NULL)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow->val;
//}


//1->2->3->4->5
//#include <stdio.h>
//#include <stdlib.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* temp = NULL;
//    struct ListNode* newnode = NULL;
//    while (cur)
//    {
//        newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//        if (newnode == NULL)
//        {
//            perror("newnode");
//            return 0;
//        }
//        newnode->val = cur->val;
//        newnode->next = temp;
//        temp = newnode;
//        cur = cur->next;
//    }
//    return newnode;
//}
//int main()
//{
//    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    n1->val = 1;
//    n2->val = 2;
//    n3->val = 3;
//    n4->val = 4;
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = NULL;
//    struct ListNode* cur = reverseList(n1);
//    while (cur)
//    {
//        printf("%d->", cur->val);
//        cur = cur->next;
//    }
//    return 0;
//}


//方法2
//改变链表方向
//交换位置
//#include <stdio.h>
//#include <stdlib.h>
//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* n1 = NULL;
//    struct ListNode* n2 = head;
//    struct ListNode* tmp = head;
//    while (tmp != NULL)
//    {
//        tmp = n2->next;
//        n2->next = n1;
//        n1 = n2;
//        n2 = tmp;
//    }
//    return n1;
//}
//struct ListNode* test()
//{
//    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    n1->val = 1;
//    n2->val = 2;
//    n3->val = 3;
//    n4->val = 4;
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = NULL;
//    return n1;
//}
//int main()
//{
//    struct ListNode* n1 = test();
//    struct ListNode* cur = reverseList(n1);
//    while (cur)
//    {
//        printf("%d->", cur->val);
//        cur = cur->next;
//    }
//    return 0;
//}


