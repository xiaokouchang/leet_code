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
//方法1
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


//方法2
//class Solution 
//{
//public:
//    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
//    {
//        if (pListHead == nullptr || k <= 0)
//        {
//            return nullptr;
//        }
//        ListNode* p = pListHead;
//        ListNode* q = pListHead;
//        while (k--)
//        {
//            //链表长度小于k
//            if (p == nullptr)
//            {
//                return nullptr;
//            }
//            p = p->next;
//        }
//        while (p != nullptr)
//        {
//            p = p->next;
//            q = q->next;
//        }
//        return q;
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


//链表的回文结构
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//class PalindromeList 
//{
//public:
//    ListNode* reverse(ListNode* A)
//    {
//        ListNode* cur = A;
//        ListNode* curnext = nullptr;
//        ListNode* tail = nullptr;
//        while (cur)
//        {
//            curnext = cur->next;
//            cur->next = tail;
//            tail = cur;
//            cur = curnext;
//        }
//        return tail;
//    }
//    ListNode* Middle(ListNode* A)
//    {
//        ListNode* fast = A;
//        ListNode* slow = A;
//        while (fast && fast->next)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        return slow;
//    }
//    bool chkPalindrome(ListNode* A) {
//        // write code here
//        ListNode* mid = Middle(A);
//        ListNode* rev = reverse(mid);
//        ListNode* cur = A;
//        while (rev)
//        {
//            if (rev->val != cur->val)
//            {
//                return false;
//            }
//            rev = rev->next;
//            cur = cur->next;
//        }
//        return true;
//    }
//};


//输入两个链表,找出它们的第一个公共结点
//https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
//方法1
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        if (headA == nullptr || headB == nullptr) {
//            return nullptr;
//        }
//        ListNode* curA = headA;
//        ListNode* curB = headB;
//        int lena = 1;
//        int lenb = 1;
//        while (curA->next) {
//            curA = curA->next;
//            lena++;
//        }
//        while (curB->next) {
//            curB = curB->next;
//            lenb++;
//        }
//        if (curA != curB) {
//            return nullptr;
//        }
//        int different = abs(lena - lenb);
//        ListNode* longlist = headA;
//        ListNode* shortlist = headB;
//        if (lena < lenb) {
//            longlist = headB;
//            shortlist = headA;
//        }
//        while (different) {
//            longlist = longlist->next;
//            different--;
//        }
//        while (longlist != shortlist) {
//            longlist = longlist->next;
//            shortlist = shortlist->next;
//        }
//        return longlist;
//    }
//};


//方法2
//class Solution 
//{
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
//    {
//        if (headA == nullptr || headB == nullptr)
//        {
//            return nullptr;
//        }
//        ListNode* curA = headA;
//        ListNode* curB = headB;
//        while (curA != curB)
//        {
//            curA = curA == nullptr ? headB : curA->next;
//            curB = curB == nullptr ? headA : curB->next;
//        }
//        return curA;
//    }
//};


//142、环形链表2
//https://leetcode.cn/problems/linked-list-cycle-ii/description/
//方法1
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while (fast && fast->next)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//            if (slow == fast)
//            {
//                ListNode* meet = slow;
//                ListNode* cur = head;
//                while (meet != cur)
//                {
//                    meet = meet->next;
//                    cur = cur->next;
//                }
//                return meet;
//            }
//        }
//        return nullptr;
//    }
//};


//方法2
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


//有效的括号
//https://leetcode.cn/problems/valid-parentheses/
//class Solution 
//{
//public:
//    bool isValid(string s) 
//    {
//        int n = s.size();
//        int i = 0;
//        stack<char> st;
//        for (i = 0; i < n; i++) 
//        {
//            if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
//            {
//                st.push(s[i]);
//            }
//            else {
//                if (st.size() == 0) 
//                {
//                    // 栈中只有右括号
//                    return false;
//                }
//                char tmp = st.top();
//                st.pop();
//                if ((tmp == '{' && s[i] != '}') ||
//                    (tmp == '[' && s[i] != ']') ||
//                    (tmp == '(' && s[i] != ')')) 
//                {
//                    return false;
//                }
//            }
//        }
//        bool ret = st.empty();
//        return ret;
//    }
//};


//用队列实现栈
//https://leetcode.cn/problems/implement-stack-using-queues/
//方法1 --- 两个队列(正着放)
//class MyStack 
//{
//public:
//    MyStack() {}
//    void push(int x) 
//    { 
//        _q1.push(x); 
//    }
//    int pop() 
//    {
//        int ret = 0;
//        //将第1个队列除了最后一个元素之外全部导入第2个队列
//        //删除第1个队列的最后一个元素
//        //将第2个队列的元素导入第1个队列
//        while (!_q1.empty()) 
//        {
//            if (_q1.size() == 1) 
//            {
//                ret = _q1.front();
//                _q1.pop();
//                break;
//            }
//            _q2.push(_q1.front());
//            _q1.pop();
//        }
//        while (!_q2.empty()) 
//        {
//            _q1.push(_q2.front());
//            _q2.pop();
//        }
//        return ret;
//    }
//    int top() 
//    {
//        //将第1个队列除了最后一个元素之外全部导入第2个队列
//        //存下第1个队列的最后一个元素,并将这个元素导入第2个队列
//        //将第2个队列的元素导入第1个队列
//        int ret = 0;
//        while (!_q1.empty()) 
//        {
//            if (_q1.size() == 1) 
//            {
//                ret = _q1.front();
//            }
//            _q2.push(_q1.front());
//            _q1.pop();
//        }
//        while (!_q2.empty()) 
//        {
//            _q1.push(_q2.front());
//            _q2.pop();
//        }
//        return ret;
//    }
//    bool empty() 
//    { 
//        return _q1.size() == 0; 
//    }
//private:
//    queue<int> _q1;
//    queue<int> _q2;
//};


//方法2 --- 两个队列(倒着放)
//class MyStack 
//{
//public:
//    MyStack() {}
//    void push(int x)
//    {
//        _q2.push(x);
//        while (!_q1.empty()) 
//        {
//            _q2.push(_q1.front());
//            _q1.pop();
//        }
//        swap(_q1, _q2);
//    }
//    int pop() 
//    {
//        int ret = _q1.front();
//        _q1.pop();
//        return ret;
//    }
//    int top() 
//    {
//        int ret = _q1.front();
//        return ret;
//    }
//    bool empty()
//    { 
//        return _q1.empty();
//    }
//private:
//    queue<int> _q1;
//    queue<int> _q2;
//};


//方法3
//1个队列
//class MyStack 
//{
//public:
//    MyStack() 
//    {}
//    void push(int x) 
//    {
//        int n = _q.size();
//        _q.push(x);
//        int i = 0;
//        for (i = 0; i < n; i++) 
//        {
//            _q.push(_q.front());
//            _q.pop();
//        }
//    }
//    int pop() 
//    {
//        int ret = _q.front();
//        _q.pop();
//        return ret;
//    }
//    int top() 
//    {
//        int ret = _q.front();
//        return ret;
//    }
//    bool empty() 
//    { 
//        return _q.empty(); 
//    }
//private:
//    queue<int> _q;
//};


//用栈实现队列
//https://leetcode.cn/problems/implement-queue-using-stacks/submissions/717468460/
//方法1
//class MyQueue 
//{
//public:
//    MyQueue() 
//    {
//
//    }
//    void push(int x) 
//    {
//        //将第1个栈的元素移到第2个栈
//        while (!_st1.empty())
//        {
//            _st2.push(_st1.top());
//            _st1.pop();
//        }
//        //第1个空栈插入元素
//        _st1.push(x);
//        //将第2个栈的元素移到第1个栈
//        while (!_st2.empty())
//        {
//            _st1.push(_st2.top());
//            _st2.pop();
//        }
//    }
//    int pop() 
//    {
//        int ret = _st1.top();
//        _st1.pop();
//        return ret;
//    }
//    int peek() 
//    {
//        int ret = _st1.top();
//        return ret;
//    }
//    bool empty() 
//    {
//        return _st1.empty();
//    }
//private:
//    stack<int> _st1;
//    stack<int> _st2;
//};


//方法2
//class MyQueue 
//{
//public:
//    MyQueue() {}
//    void push(int x)
//    { 
//        _st1.push(x);
//    }
//    int pop() 
//    {
//        int ret = 0;
//        while (!_st1.empty()) 
//        {
//            if (_st1.size() == 1)
//            {
//                ret = _st1.top();
//                _st1.pop();
//                break;
//            }
//            _st2.push(_st1.top());
//            _st1.pop();
//        }
//        while (!_st2.empty()) 
//        {
//            _st1.push(_st2.top());
//            _st2.pop();
//        }
//        return ret;
//    }
//    int peek()
//    {
//        int ret = 0;
//        while (!_st1.empty()) 
//        {
//            if (_st1.size() == 1) 
//            {
//                ret = _st1.top();
//            }
//            _st2.push(_st1.top());
//            _st1.pop();
//        }
//        while (!_st2.empty()) 
//        {
//            _st1.push(_st2.top());
//            _st2.pop();
//        }
//        return ret;
//    }
//    bool empty() 
//    { 
//        return _st1.empty(); 
//    }
//private:
//    stack<int> _st1;
//    stack<int> _st2;
//};


//设计循环队列
//https://leetcode.cn/problems/design-circular-queue/
//class MyCircularQueue 
//{
//public:
//    MyCircularQueue(int k) 
//    {
//        front = rear = 0;
//        capacity = k + 1;
//        arr = new int[capacity];
//    }
//    bool enQueue(int value) 
//    {
//        if (isFull())
//        {
//            return false;
//        }
//        arr[rear] = value;
//        rear = (rear + 1) % capacity;
//        return true;
//    }
//    bool deQueue() 
//    {
//        if (isEmpty())
//        {
//            return false;
//        }
//        front = (front + 1) % capacity;
//        return true;
//    }
//    int Front() 
//    {
//        if (isEmpty())
//        {
//            return -1;
//        }
//        return arr[front];
//    }
//    int Rear() 
//    {
//        if (isEmpty())
//        {
//            return -1;
//        }
//        return arr[(rear + capacity - 1) % capacity];
//    }
//    bool isEmpty()
//    {
//        return rear == front;
//    }
//    bool isFull() 
//    {
//        return (rear + 1) % capacity == front;
//    }
//private:
//    int* arr;
//    int front;
//    int rear;
//    int capacity;
//};