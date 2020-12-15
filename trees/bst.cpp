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
  void printpreorder(TreeNode *r)
  {
    if (r == NULL)
       return;
    cout <<r->val<<" ";
    printpreorder(r->left);
    printpreorder(r->right);

  }
  void printinorder(TreeNode *r)
  {
    if (r == NULL)
      return;
    printinorder(r->left);
    cout << r->val <<" ";
    printinorder(r->right);
  }
  void printpostorder(TreeNode *r)
  {
    if (r == NULL)
      return;
    printpostorder(r->left);
    printpostorder(r->right);
    cout << r->val << " ";
  }
  TreeNode* itersearch(int val)
  {
    if(root == NULL)
       return root;
    else
    {
      TreeNode* temp;
      temp =root;
      while(temp!=NULL)
      {
        if (temp->val == val)
          return temp;
        else if(temp->val < val)
            temp = temp->right;
        else
          temp = temp->left;
        
           
      }
    }
    return NULL;
  }
  TreeNode * recsearch(TreeNode * r, int val) {
    if (r == NULL || r -> val == val)
      return r;
 
    else if (val < r -> val)
      return recsearch(r -> left, val);
 
    else
      return recsearch(r -> right, val);
    return NULL;
  }
  int height(TreeNode* r)
  {
    if(r == NULL)
      return -1;
    else
    {
      int lheight = height(r->left);
      int rheight = height (r->right);
      if (lheight > rheight)
         return (lheight+1);
      else
        return (rheight+1);
      
    }
    
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
        cout <<"search" <<endl;
        cout << " enter value of tree node to b searched: ";
        cin >>val;
        // new_node=obj.itersearch(val);
          new_node = obj.recsearch(obj.root,val);
          if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
        break;
        
       
     
    case 3:
      
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
        cout << "print pre order" <<endl;
       obj.printpreorder(obj.root);
       cout <<endl;
        cout << "print in order" <<endl;
       obj.printinorder(obj.root);
       cout <<endl;
        cout << "print post order" <<endl;
       obj.printpostorder(obj.root);
       cout <<endl;
      
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
        cout<<"height of a tree" <<endl;
        cout<<obj.height(obj.root)<<endl;
        break;
     
    
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}
 