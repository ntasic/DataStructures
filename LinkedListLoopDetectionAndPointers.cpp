// Example program
#include <iostream>
#include <string>
#include <set>
#include <bits/stdc++.h> 

using namespace std;

struct Node{
    int value;
    Node* next;
};

void push(Node** head, int value)
{
    Node* temp = new Node;
    temp->value = value;
    temp->next = (*head);
    
    (*head) = temp;
}

void displayList(Node* head)
{
    Node *temp = head;
    
    while(temp != NULL)
    {
        cout<<temp->value<<'\t';
        temp=temp->next;
    }
};

bool detectLoop(Node* head)
{
    unordered_set<Node*> s;
    
    //cout<< "something";
    
    while(head != NULL)
    {
        if(s.find(head) != s.end())
            return true;
            
        s.insert(head);
        
        head = head->next;
    }
    
    return false;
}

int main()
{
    Node* head = NULL; 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
    
    displayList(head);
    
    head->next->next->next->next = head; 
    
    cout<< detectLoop(head);
    
    return(0);
}

