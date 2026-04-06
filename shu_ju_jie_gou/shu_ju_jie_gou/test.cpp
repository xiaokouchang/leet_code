//消失的数字
//https://leetcode.cn/problems/missing-number-lcci/
//方法1
//class Solution 
//{
//public:
//    int missingNumber(vector<int>& nums) 
//    {
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        int i = 0;
//        for (i = 0; i < n; i++) 
//        {
//            if (nums[i] != i) 
//            {
//                return i;
//            }
//        }
//        return n;
//    }
//};


//方法2
//等差数列求和
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n = nums.size();
//        // 等差数列总和 = （首项 + 尾项）* 项数 / 2
//        int total = (1 + n) * n / 2;
//        // 当前数组的总和
//        int sum = 0;
//        for (int i = 0; i < n; i++) {
//            sum += nums[i];
//        }
//        // 缺少值 = 等差数列总和 - 数组总和
//        return total - sum;
//    }
//};


//旋转数组
//https://leetcode.cn/problems/rotate-array/
//方法1
//class Solution 
//{
//public:
//    void reverse(vector<int>& nums, int start, int end)
//    {
//        while (start < end)
//        {
//            swap(nums[start], nums[end]);
//            start++;
//            end--;
//        }
//    }
//    void rotate(vector<int>& nums, int k) 
//    {
//        int n = nums.size();
//        k %= n;
//        reverse(nums, 0, n - 1);
//        reverse(nums, 0, k - 1);
//        reverse(nums, k, n - 1);
//    }
//};


//方法2
//使用额外空间
//class Solution 
//{
//public:
//    void rotate(vector<int>& nums, int k)
//    {
//        int n = nums.size();
//        vector<int> tmp(nums);
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            int index = (i + k) % n;
//            nums[index] = tmp[i];
//        }
//    }
//};


//移除元素
//https://leetcode.cn/problems/remove-element/
//方法1
//class Solution 
//{
//public:
//    int removeElement(vector<int>& nums, int val) 
//    {
//        int left = 0;
//        int right = 0;
//        int n = nums.size();
//        for (right = 0; right < n; right++)
//        {
//            if (nums[right] != val)
//            {
//                swap(nums[left], nums[right]);
//                left++;
//            }
//        }
//        return left;
//    }
//};


//删除数组中的重复项
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//class Solution 
//{
//public:
//    int removeDuplicates(vector<int>& nums) 
//    {
//        int n = nums.size();
//        if (n == 0)
//        {
//            return 0;
//        }
//        int left = 0;
//        int right = 0;
//        for (right = 0; right < n; right++)
//        {
//            if (nums[left] != nums[right])
//            {
//                left++;
//                nums[left] = nums[right];
//            }
//        }
//        return left + 1;
//    }
//};


//方法2
//从后向前移动
//class Solution 
//{
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
//    {
//        int i = m + n - 1;
//        m--;
//        n--;
//        while (n >= 0)
//        {
//            if (m >= 0 && nums1[m] > nums2[n])
//            {
//                nums1[i] = nums1[m];
//                m--;
//                i--;
//            }
//            else
//            {
//                nums1[i] = nums2[n];
//                n--;
//                i--;
//            }
//        }
//    }
//};


//删除链表中等于给定值val的所有结点
//https://leetcode.cn/problems/remove-linked-list-elements/submissions/715319617/
//方法1
//struct ListNode* removeElements(struct ListNode* head, int val) 
//{
//    struct ListNode* cur = head;
//    struct ListNode* prev = NULL;
//    while (cur) 
//    {
//        if (cur->val == val) 
//        {
//            if (cur == head) 
//            {
//                struct ListNode* del = cur;
//                cur = head = del->next;
//                free(del);
//            }
//            else 
//            {
//                struct ListNode* del = cur;
//                prev->next = cur->next;
//                cur = prev;
//                free(del);
//            }
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}


//方法2
//class Solution 
//{
//public:
//    ListNode* removeElements(ListNode* head, int val) 
//    {
//        ListNode* newHead = new ListNode(-1);
//        newHead->next = head;
//        ListNode* cur = newHead;
//        while (cur->next)
//        {
//            if (cur->next->val == val)
//            {
//                cur->next = cur->next->next;
//            }
//            else
//            {
//                cur = cur->next;
//            }
//        }
//        head = newHead->next;
//        delete newHead;
//        newHead = nullptr;
//        return head;
//    }
//};


//反转链表
//https://leetcode.cn/problems/reverse-linked-list/
//方法1
//class Solution 
//{
//public:
//    ListNode* reverseList(ListNode* head) 
//    {
//        if (head == nullptr)
//        {
//            return nullptr;
//        }
//        ListNode* cur = head;
//        stack<ListNode*> st;
//        while (cur)
//        {
//            st.push(cur);
//            cur = cur->next;
//        }
//        ListNode* Head = st.top();
//        st.pop();
//        cur = Head;
//        while (!st.empty())
//        {
//            cur->next = st.top();
//            st.pop();
//            cur = cur->next;
//        }
//        cur->next = nullptr;
//        return Head;
//    }
//};


//方法2
//class Solution 
//{
//public:
//    ListNode* reverseList(ListNode* head) 
//    {
//        if (head == nullptr)
//        {
//            return nullptr;
//        }
//        ListNode* cur = head;
//        ListNode* tmp = nullptr;//保存链表的下一个节点
//        ListNode* prev = nullptr;//尾节点
//        while (cur)
//        {
//            tmp = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = tmp;
//        }
//        return prev;
//    }
//};


//链表的回文结构
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//方法1
//class PalindromeList
//{
//public:
//    bool chkPalindrome(ListNode* A) 
//    {
//        if (A == nullptr)
//        {
//            return false;
//        }
//        // write code here
//        ListNode* cur = A;
//        stack<ListNode*> st;
//        while (cur)
//        {
//            st.push(cur);
//            cur = cur->next;
//        }
//        ListNode* tail = st.top();
//        st.pop();
//        cur = A;
//        ListNode* slow = A;
//        ListNode* fast = A;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        while (cur != slow && tail != slow)
//        {
//            if (cur->val != tail->val)
//            {
//                return false;
//            }
//            cur = cur->next;
//            tail = st.top();
//            st.pop();
//        }
//        return true;
//    }
//};


//方法2
//直接比较值
//class PalindromeList
//{
//public:
//    bool chkPalindrome(ListNode* A) 
//{
//        if (A == nullptr)
//        {
//            return false;
//        }
//        // write code here
//        ListNode* cur = A;
//        stack<int> st;
//        while (cur)
//        {
//            st.push(cur->val);
//            cur = cur->next;
//        }
//        cur = A;
//        while (cur)
//        {
//            if (cur->val != st.top())
//            {
//                return false;
//            }
//            cur = cur->next;
//            st.pop();
//        }
//        return true;
//    }
//};


//链表的中间节点
//https://leetcode.cn/problems/middle-of-the-linked-list/submissions/632809308/
//方法1
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


//方法2---使用栈计数
//class Solution 
//{
//public:
//    ListNode* middleNode(ListNode* head) 
//    {
//        stack<ListNode*> st;
//        if (head == nullptr)
//        {
//            return nullptr;
//        }
//        ListNode* cur = head;
//        while (cur)
//        {
//            st.push(cur);
//            cur = cur->next;
//        }
//        int mid = st.size() / 2;
//        cur = head;
//        while (mid > 0)
//        {
//            cur = cur->next;
//            mid--;
//        }
//        return cur;
//    }
//};


//链表倒数第k个节点
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//class Solution 
//{
//public:
//    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//    {
//        stack<ListNode*> st;
//        if (pListHead == nullptr) 
//        {
//            return nullptr;
//        }
//        ListNode* cur = pListHead;
//        ListNode* tmp = pListHead;
//        while (cur) 
//        {
//            st.push(cur);
//            cur = cur->next;
//        }
//        if (k > st.size() || k == 0) 
//        {
//            return nullptr;
//        }
//        int n = st.size();
//        int i = 0;
//        for (i = k; i > 1; i--) 
//        {
//            tmp = tmp->next;
//            st.pop();
//        }
//        cur = st.top();
//        return cur;
//    }
//};


//合并两个有序链表
//https://leetcode.cn/problems/merge-two-sorted-lists/submissions/715403201/
//方法1
//class Solution
//{
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
//    {
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        if (list2 == nullptr)
//        {
//            return list1;
//        }
//        ListNode* newHead = new ListNode(-1);
//        ListNode* lt1 = list1;
//        ListNode* lt2 = list2;
//        ListNode* head = newHead;
//        ListNode* tail = newHead;
//        while (lt1 && lt2)
//        {
//            if (lt1->val < lt2->val)
//            {
//                tail->next = lt1;
//                tail = tail->next;
//                lt1 = lt1->next;
//            }
//            else
//            {
//                tail->next = lt2;
//                tail = tail->next;
//                lt2 = lt2->next;
//            }
//        }
//        if (lt1)
//        {
//            tail->next = lt1;
//        }
//        if (lt2)
//        {
//            tail->next = lt2;
//        }
//        ListNode* Head = newHead->next;
//        delete newHead;
//        newHead = nullptr;
//        return Head;
//    }
//};


//方法2
//class Solution
//{
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
//    {
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        if (list2 == nullptr)
//        {
//            return list1;
//        }
//        ListNode* lt1 = list1;
//        ListNode* lt2 = list2;
//        ListNode* head = nullptr;
//        ListNode* tail = nullptr;
//        while (lt1 && lt2)
//        {
//            if (lt1->val < lt2->val)
//            {
//                if (head == nullptr)
//                {
//                    head = tail = lt1;
//                }
//                else
//                {
//                    tail->next = lt1;
//                    tail = tail->next;
//                }
//                lt1 = lt1->next;
//            }
//            else
//            {
//                if (head == nullptr)
//                {
//                    head = tail = lt2;
//                }
//                else
//                {
//                    tail->next = lt2;
//                    tail = tail->next;
//                }
//                lt2 = lt2->next;
//            }
//        }
//        if (lt1)
//        {
//            tail->next = lt1;
//        }
//        if (lt2)
//        {
//            tail->next = lt2;
//        }
//        return head;
//    }
//};


//链表分割
//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//class Partition 
//{
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        // write code here
//        ListNode* lesshead = new ListNode(-1);
//        ListNode* greathead = new ListNode(-1);
//        ListNode* lesstail = lesshead;
//        ListNode* greattail = greathead;
//        ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                lesstail->next = cur;
//                lesstail = lesstail->next;
//            }
//            else {
//                greattail->next = cur;
//                greattail = greattail->next;
//            }
//            cur = cur->next;
//        }
//        lesstail->next = greathead->next;
//        greattail->next = nullptr;
//        ListNode* Head = lesshead->next;
//        delete lesshead;
//        delete greathead;
//        return Head;
//    }
//};


//142、环形链表2
//https://leetcode.cn/problems/linked-list-cycle-ii/description/
//class Solution 
//{
//public:
//    ListNode* detectCycle(ListNode* head) 
//    {
//        set<ListNode*> s;
//        ListNode* cur = head;
//        while (cur)
//        {
//            if (s.count(cur))
//            {
//                return cur;
//            }
//            else
//            {
//                s.insert(cur);
//                cur = cur->next;
//            }
//        }
//        return nullptr;
//    }
//};