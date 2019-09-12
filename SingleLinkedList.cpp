// Example program
#include <iostream>
#include <string>

using namespace std;

struct node
{
    int data;
    node* next;
};

class singledLinkedList
{
    private: 
    node *head, *tail;
    int size;
    
    public:
    singledLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    };
    
    void createNode(int value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        size++;
        
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    };
    
    void displayList()
    {
        node *temp = head;
        
        while(temp != NULL)
        {
            cout<<temp->data<<'\t';
            temp=temp->next;
        }
    };
    
    void insertNodeAtStart(int value)
    {
        if(size == 0) createNode(value);
        else
        {
            node* temp = new node;
            
            temp->data = value;
            temp->next = head;
            head = temp;
            size++;
        }
    };
    
    void insertNodeAtPosition(int pos, int value)
    {   
        if(pos == 1) insertNodeAtStart(value)
        else if(pos == size) createNode(value)
        else
        {
            node* temp = new node;
            temp->data = value;
            
            node* curr = head;
            for(int i=1; i<pos-1; i++)
                curr = curr->next;
                
            temp->next = curr->next;
            curr->next = temp;
            size++;
        }
    };
    
    void deleteFirstNode()
    {
        if(size != 0)
        {
            if( head == tail ) 
            {
                delete head;
                
                head = NULL;
                tail = NULL;
            }
            else
            {
                node *temp = head;
                
                head = head->next;
                size--;
                
                delete temp;
            }
        }
    }
    
    void deleteLastNode()
    {
        if( head == tail ) 
        {
            delete head;
            
            head = NULL;
            tail = NULL;
        }
        else
        {
            node* curr = head;
            node* prev = head;
            
            while(curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            
            tail = prev;
            tail->next = NULL;
            delete curr;
        }
    }
    
    void deletePosition(int pos)
    {
        if(pos == 1) deleteFirstNode(value)
        else if(pos == size) deleteLastNode(value)
        else
        {
            node* curr = head;
            node* prev;
            
            for(int i=1; i < pos; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            
            prev->next = curr->next;
            delete curr;
        }
    }
    
};

int main()
{
    singledLinkedList obj;
    obj.createnode(25);
    
    obj.insertPosition(5,60);
    obj.display();
    system("pause");
	return 0;
    /*
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insertStart(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insertPosition(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deleteFirst();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deleteLast();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deletePosition(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	system("pause");*/
	return 0;
}
