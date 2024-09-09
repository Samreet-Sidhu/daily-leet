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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        //matrix intialize kiya with -1 values all over
      vector<vector<int>> matrix(m,vector<int>(n,-1));
      // traversal k liye intialize kar diye
      int toprow=0, bottomrow =m-1, leftcolumn=0, rightcolumn=n-1;
      // jab tak linkedlist khtam nhi ho jati
      while (head){
        // phele top row fill hogi
        for (int col= leftcolumn; col<=rightcolumn && head; col++){
            matrix[toprow][col] = head->val;
            head= head-> next;
        }
        toprow++;
        // rightmopst column fill karenge
        for (int row= toprow; row<=bottomrow && head; row++){
            matrix[row][rightcolumn] = head->val;
            head = head->next;
        }
        rightcolumn--;
        // bottom row fill 
        for (int col = rightcolumn; col >= leftcolumn && head; --col) {
            matrix[bottomrow][col] = head->val;
            head = head->next;
        }
        bottomrow--;
        //lefftcolum fill krenge
        for (int row = bottomrow; row >= toprow && head; --row) {
            matrix[row][leftcolumn] = head->val;
            head = head->next;
        }
        leftcolumn++;
      }
      return matrix;

    }
};
