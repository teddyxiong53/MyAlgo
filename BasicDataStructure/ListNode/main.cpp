#include <iostream>
#include <memory>
#include <stdio.h>
#include <functional>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int v):val(v), next(nullptr){}
};

ListNode* createList(int len)
{
    ListNode *head = new ListNode(len);
    ListNode *root = head;
    int i= 1;
    while(len > 0) {
        ListNode *s = new ListNode(i);
        head->next = s;
        head = s;
        i++;
        len--;
    }
    return root->next;
}
void printList(ListNode *head)
{
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
ListNode *reverse(ListNode *head)
{
    ListNode *node = nullptr;

    while(head) {
        ListNode *next = head->next;

        head->next = node;

        node = head;
        head = next;
    }
    return node;

}
ListNode *createList(int arr[], int len)
{

    // printf("len:%d\n", len);
    int i = 0;
    ListNode *head = new ListNode(len);
    ListNode *root = head;
    while(len > 0) {
        ListNode *s = new ListNode(arr[i]);
        head->next = s;
        head = s;
        len --;
        i++;
    }
    return root->next;
}
ListNode *removeDuplicate(ListNode* head)
{
    ListNode *cur = head;
    while(cur->next) {
        if(cur->val == cur->next->val) {
            ListNode *next = cur->next->next;
            delete cur->next;
            cur->next = next;
        } else {
            cur = cur->next;
        }

    }
    return head;
}
ListNode *merge(ListNode *a, ListNode *b)
{
    ListNode dummy(0), *tail = &dummy;
    while(a&&b) {
        tail->next = a;
        tail = a;
        a = a->next;
        tail->next = b;
        tail = b;
        b = b->next;
    }
    tail->next = a?a:b;
    return dummy.next;
}

void moveNode(ListNode **destRef, ListNode **srcRef)
{
    ListNode *newNode = *srcRef;
    *srcRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

ListNode *sortedMerge(ListNode *a, ListNode *b)
{
    ListNode dummy(0), *tail = &dummy;
    while(a&&b) {
        if(a->val <= b->val) {
            moveNode(&(tail->next), &a);
        } else {
            moveNode(&(tail->next), &b);
        }
        tail = tail->next;
    }
    tail->next = a? a:b;
    return dummy.next;
}

bool hasCircle(ListNode *head)
{
    if(head == nullptr) {
        return false;
    }
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}
int findMiddle(ListNode *head)
{
    
}
void test_reverse()
{
    printf("test reverse\n");
    ListNode *a = createList(5);
    printf("before reverse\n");
    printList(a);
    //逆序
    printf("after reverse\n");
    printList(reverse(a));
}
void test_removeDuplicate()
{
    printf("test remove duplicate\n");
    int a_val[] = {1,1,2,2,3,4};
    ListNode *a = createList(a_val, sizeof(a_val)/sizeof(int));
    printf("original List:\n");
    printList(a);
    printf("after remove duplicate\n");
    printList(removeDuplicate(a));
}
void test_merge()
{
    printf("test merge\n");
    int a_val[] = {1,3,5,7};
    int b_val[] = {2,4,6};
    ListNode *a = createList(a_val, sizeof(a_val)/sizeof(int));
    ListNode *b = createList(b_val, sizeof(b_val)/sizeof(int));
    printf("after merge\n");
    printList(merge(a, b));
}
void test_moveNode()
{
    printf("test move node\n");
    int a_val[] = {1,3,5,7};
    int b_val[] = {2,4,6};
    ListNode *a = createList(a_val, sizeof(a_val)/sizeof(int));
    ListNode *b = createList(b_val, sizeof(b_val)/sizeof(int));
    printf("after move node\n");
    moveNode(&a, &b);
    printList(a);
    printList(b);
}
void test_sortedMerge()
{
    printf("test sorted merge\n");
    int a_val[] = {1,3,5,7};
    int b_val[] = {2,4,6};
    ListNode *a = createList(a_val, sizeof(a_val)/sizeof(int));
    ListNode *b = createList(b_val, sizeof(b_val)/sizeof(int));
    printf("after sorted merge\n");
    printList(sortedMerge(a, b));
}
void test_cross()
{
    ListNode *a = new ListNode(1);
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *b = new ListNode(10);
    a->next = n1;
    n1->next = n2;
    b->next = n4;
    n4->next = n2;
    n2->next = n3;
    printList(a);
    printList(b);
    printf("is a cross b?\n");
    ListNode *b_root = b;

    while(a) {
        ListNode *a_last = a;
        a = a->next;
    }
}
void test_hasCircle()
{
    ListNode *a = new ListNode(1);
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    a->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = a;
    if(hasCircle(a)) {
        printf("list has circle\n");
    } else {
        printf("list has no circle\n");
    }
}
int main()
{
    // test_reverse();
    // test_removeDuplicate();
    // test_merge();
    // test_moveNode();
    // test_sortedMerge();
    // test_cross();
    test_hasCircle();
}
