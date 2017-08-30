//Leecode #2 number add number
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* initialList(int *a, int len){
    ListNode* l = new ListNode(*a);
    ListNode* temp = l;
    len--;
    while(len>0){
        temp->next = new ListNode(*(++a));
        temp = temp->next;
        len--;
    }
    return l;
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l3 =new ListNode(-1);
        ListNode* tempL3 = l3;
        while(l1&&l2){
            
            int add =  l1->val+l2->val;
            add+=carry;
            if(add>=10){
                carry = 1;
                add-=10;
            }else{
                carry = 0;
            }
            tempL3->next = new ListNode(add);
            l1 = l1->next;
            l2 = l2->next;
            tempL3 = tempL3->next;
        }
        while (l1) {
            int add = l1->val+carry;
            if(add==10){
                carry = 1;
                add = 0;
            }else{
                carry = 0;
            }
            l1=l1->next;
            tempL3->next = new ListNode(add);
            tempL3 = tempL3->next;
        }
        while (l2) {
            int add = l2->val+carry;
            if(add==10){
                carry = 1;
                add = 0;
            }else{
                carry = 0;
            }
            l2 = l2->next;
            tempL3->next = new ListNode(add);
            tempL3 = tempL3->next;
        }
        if(carry==1){
            tempL3 ->next = new ListNode(1);
        }
        return l3->next;
    }
};
int main ()
{
    int l1[] = {2,4,3};
    int l2[] = {5,6,4};
    ListNode* ln1;
    ListNode* ln2;
    ln1 = initialList(l1,3);
    ln2 = initialList(l2,3);
    Solution s1;
    ListNode *result =  s1.addTwoNumbers(ln1, ln2);
    while (result!=nullptr) {
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}
