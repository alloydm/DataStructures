#include <iostream>
using namespace std;
class Node
{
    public:
         int key,data;
         Node * next;
         Node()
         {
             key=0;
             data=0;
             next = NULL;
         }
         
};
class Singlylist
{
    public:
      Node * head;
      Singlylist()
      {
          head = NULL;
      }
     
    //   1.check if node exists using key
    Node * nodeexist(int k)
    {
        Node * temp =NULL;
        Node * ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key==k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        
        
        return temp;
    }
   
    // 3. node prepend
    void prepend(Node * n)
    {
         if (nodeexist(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
        n->next = head;
        head = n;
        cout << "node prepend" <<endl;
    }
    }
    void reverse()
    {
        Node * next,*curr,*prev;
        curr=head;
        prev=NULL;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        cout<<"linkedlist reversed"<<endl;
    }
    
    
    
    // 7. printing
    void print()
    {
        if(head == NULL)
        {
            cout << "no values in list" <<endl;

        }
        else
        {
            cout << "values:" <<endl;
            Node * temp =head;
            while (temp != NULL)
            {
                cout << temp->key <<"," <<temp->data << "->";
                temp = temp->next;
            }
        }
        
    }
};
int main()
{
     Singlylist s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
 
    cout << "1. prependNode()" << endl;
 
    cout << "2. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
 
    switch (option) {
    
   
 
    case 1:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prepend(n1);
      break;
 
  
    case 2:
      s.print();
      break;
    case 3:
      s.reverse();
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
