#include <iostream>
#define SPACE 10
using namespace std;

class TreeNode {
  public:
    int val;
  TreeNode * left;
  TreeNode * right;
 
  TreeNode() {
    val = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    val = v;
    left = NULL;
    right = NULL;
  }
};
class Bst
{
    public:
      TreeNode* root;
      Bst()
      {
          root = NULL;
      }
      bool isempty()
      {
          if(root == NULL)
            return true;
          else
            return false;
          
      }
      void insert(TreeNode *new_node)
      {
          if(root == NULL)
            
            {
                root = new_node; 
                cout << "value inserted" <<endl;
            }
          else 
             {TreeNode *temp = root;
             while(temp != NULL)
             {
                 if(temp->val == new_node->val) 
                     return;
                 else if(((temp->val) > (new_node->val)) && (temp->left == NULL))
                    {
                        temp->left = new_node;
                        cout << "value inserted to the left" <<endl;
                        break;
                    }
                else if((temp->val) > (new_node->val))
                    temp = temp->left;
                else if(((temp->val) < (new_node->val)) && (temp->right == NULL))
                    {
                        temp->right = new_node;
                        cout << "value inserted to the right" <<endl;
                        break;
                    }
                else 
                    temp = temp->right;

                
             }}
      }



      void print2D(TreeNode * r, int space) {
        if (r == NULL) // Base case  1
        return;
        space += SPACE; // Increase distance between levels   2
        print2D(r -> right, space); // Process right child first 3 
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5 
        cout << " "; // 5.1  
        cout << r -> val << "\n"; // 6
        print2D(r -> left, space); // Process left child  7
  }
      
};

    
int main() {
     Bst obj;
  int option, val;
 
  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "5. Height of Tree" << endl;

    cout << "0. Exit Program" << endl;
 
    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
      cin >> val;
      new_node -> val = val;
      obj.insert(new_node);
      cout << endl;
      break;
    case 2:
     
    case 3:
      
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
    //   cout << "Print Level Order BFS: \n";
    //   obj.printLevelOrderBFS(obj.root);
    //   cout << endl;
      //	      cout <<"PRE-ORDER: ";
      //	      obj.printPreorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"IN-ORDER: ";
      //	      obj.printInorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"POST-ORDER: ";
      //	      obj.printPostorder(obj.root);
      break;
    case 5:
     
    
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}
 