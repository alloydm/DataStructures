#include <iostream>
using namespace std;
class Node {
  public:
    int key;
  int data;
  Node * next;
 
  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};
 
class CircularLinkedList {
  public:
    Node * head;
 
  CircularLinkedList() {
    head = NULL;
  }
//   1.check if node exists
  Node * nodexist(int k)
  {
      Node* temp =NULL;
      Node* ptr = head;
      if (ptr == NULL)
      {
          return temp;
      }
      else
      {
          do
          {
              if(ptr->key == k)
              {
                  temp = ptr;
              }
              ptr = ptr->next;
          } while (ptr!=head);
          return temp;
          
      }
      
  }
//   2.append node
  void appendnode(Node *n)
  {
      if(nodexist(n->key)!=NULL)
      {
          cout <<"Node already exists" <<endl;
      }
      else
      {
          if(head == NULL)
          {
              head = n;
              n->next=head;
              cout <<"node appended"<<endl;
          }
          else
          {
              Node* ptr = head;
              while(ptr->next!=head)
              {
                  ptr=ptr->next;
              }
              ptr->next=n;
              n->next=head;
              cout <<"node appended" <<endl;
          }
          
      }
      
  }
  
// 3.prepend node
  void prependnode(Node* n)
  {
      if(nodexist(n->key)!=NULL)
      {
          cout <<"node already there"<<endl;
      }
      else
      {
          if(head == NULL)
          {
              head = n;
              n->next = head;
              cout <<"node prepended"<<endl;
          }
          else
          {
              Node* ptr = head;
              while(ptr->next!=head)
              {
                  ptr = ptr->next;
              }
              ptr->next = n;
              n->next = head;
              head = n;
              cout <<"prepend node"<<endl;
          }
          
      }
      
  }
//   4.insert node
   void insertnode(int k, Node* n)
   {
       Node* ptr = nodexist(k);
       if(ptr==NULL)
       {
           cout <<"no node exists"<<endl;
       }
       else
       {
           if(nodexist(n->key)!=NULL)
           {
               cout <<"cannot insert"<<endl;
           }
           else
           {
               if(ptr->next == head)
               {
                   n->next = head;
                   ptr->next = n;
                   cout<<"node inserted"<<endl;
               }
               else
               {
                   n->next=ptr->next;
                   ptr->next = n;
                    cout<<"node inserted"<<endl;
               }
           }
           
       }
       
   }
   void deletenode(int k)
   {
       Node* ptr =nodexist(k);
       if(ptr == NULL)
       {
           cout <<"node not there"<<endl;
            
      }
      else
      {
          if(ptr == head)
          {
              if(head->next == head)
              {
                  head=NULL;
                  cout <<"node deleted"<<endl;
              }
              else
              {
                  Node* ptr =head;
                  while(ptr->next!=head)
                  {
                      ptr = ptr->next;
                  }
                  ptr->next = head->next;
                  head = head->next;
                  cout <<"node deletd" <<endl;
              }
              
          }
          else
          {
              Node* temp =NULL;
              Node* prev = head;
              Node * curr = head->next;
              while (curr!=NULL)
              {
                  if(curr->key == k)
                  {
                      temp = curr;
                      curr = NULL;
                  }
                  else
                  {
                      prev=prev->next;
                      curr = curr->next;
                  }
                  
              }
              prev->next = temp->next;
              cout << "node deletd" <<endl;
          }
          
          
      }
   }
   // 6th update node
  void updateNodeByKey(int k, int n) {
 
    Node * ptr = nodexist(k);
    if (ptr != NULL) {
      ptr -> data = n;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }
 
  }
 
  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Circular Linked List";
    } else {
      cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;
 
      Node * temp = head;
 
      do {
        cout << "(" << temp-> key << "," << temp-> data << "," << temp-> next << ") --> ";
        temp = temp-> next;
      } while (temp != head);
    }
 
  }
 


};
int main()
{
    CircularLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.appendnode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
 
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prependnode(n1);
      break;
 
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
 
      obj.insertnode(k1, n1);
      break;
 
    case 4:
 
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deletenode(k1);
 
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);
 
      break;
    case 6:
      obj.printList();
 
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
    
    
   
    return 0;
}
