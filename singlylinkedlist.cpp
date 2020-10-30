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
         Node(int k , int d)
         {
             key = k;
             data = d;
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
      Singlylist(Node *n)
      {
          head = n;
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
    // 2.append a node to list
    void appendnode(Node * n)
    {
        Node * val =nodeexist(n->key);
       

        if(val !=NULL)
        {
            cout << "cannot append since key already there" <<endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout <<"node appended" <<endl;

            }
            else
            {
                Node * ptr =head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout <<"node appended" <<endl;

            }
            
        }
        
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
    // 4.insert a node even in b/w
    void insertnode(int k ,Node * n)
    {
        Node *ptr = nodeexist(k);
        if(ptr == NULL)
        {
            cout << "No node exists with that key" <<endl;
        }
        else
        {
            if(nodeexist(n->key)!=NULL)
            {
                cout << "cannot insert this node again" <<endl;

            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" <<endl;
            }
            
        }
        
    }
    // 5. delete a node
    void deletenode(int k)
    {
        if(head == NULL)
        {
            cout << "list is empty cannot delete" <<endl;

        }
        else if(head != NULL)
        {
            if(head ->key == k)
            {
                head = head ->next;
                cout << "NOde deleted "<<endl;

            }
            else
            {
                Node * temp =NULL;
                Node * prevptr = head;
                Node * currptr = head->next;
                while (currptr != NULL)
                {
                    if(currptr->key == k)
                    {
                        temp = currptr;
                        currptr =NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currptr = currptr ->next;
                    }
                    
                }
                if(temp != NULL)
                {
                    prevptr->next = temp->next;
                }
                else
                {
                    cout <<"node doesnt exist" <<endl;
                }
                
            }
            
        }
    }
    // 6. update node
    void update(int k,int d)
    {
        Node * ptr = nodeexist(k);
        if (ptr != NULL)
        {
            ptr->data=d;
            cout << "node updated" <<endl;
        }
        else
        {
            cout << "node doesnt exist" <<endl;
        }
        

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
                cout << temp->key <<"," <<temp->data <<endl;
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
    
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendnode(n1);
      cout<<n1->key<<" = "<<n1->data<<endl;
      break;
 
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prepend(n1);
      break;
 
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
 
      s.insertnode(k1, n1);
      break;
 
    case 4:
 
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deletenode(k1);
 
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.update(key1, data1);
 
      break;
    case 6:
      s.print();
 
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
