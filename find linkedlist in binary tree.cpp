/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
          return dfs(head, head, root);
    }  
    //head: Always points to the start of the linked list.
    //current: Points to the current node of the linked list being compared.
    //root: Points to the current binary tree node.
    bool dfs(ListNode *head, ListNode *cur, TreeNode *root){
        //linkedlist traverse karte karte last tak pahunch gya iska matlab saare elements mil gye tree me 
        if (cur== nullptr){
            return true;
        }
        //tree traversal me hum last me pahunch gye matlab abhi tak hame first element bhi nhi mila toh false return karenge
        if (root == nullptr){
            return false;
        }
        // jab hum linkedlist me traverse kar rahe the toh current k corresponding element hme tree me mil gya toh hum linkedlist k next element pe move kar jayenge
        if (cur->val==root->val){
            cur=cur->next;
        }
        //agr hmara current element toh match nhi kar raha par linkedlist ka first element yani ki head match karta hai toh yeh assume karna hai ki shyd ab iss head wale treenode se hmari linkedlist start karti hai
        else if (head->val == root->val){
            head = head->next;
        }
        //agar kuch nhi match karta toh matlab hme dubara se alag path par check karna pdega
        else {
            cur=head;
        }
        // tree k left and right hise me dekho
        return dfs(head, cur, root->left) || dfs(head, cur, root->right);
    }
};
