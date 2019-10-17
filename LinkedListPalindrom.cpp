//113
//Recursive program to check if a given linked list is palindrome 
#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>

using namespace std;
  
/* Link list node */
struct Node { 
    char data; 
    Node* next; 
}; 

bool isPalindromeUtil(Node** left, Node* right)
{
    if(right == NULL)
        return true;
    
    bool isp = isPalindromeUtil(left, right->next);
    if(isp == false)
        return false;
        
    isp = ((*left)->data == right->data);
    (*left) = (*left)->next;
    
    return isp;
}
  
// A wrapper over isPalindromeUtil() 
bool isPalindrome(Node* head) 
{ 
    return isPalindromeUtil(&head, head); 
} 
  
/* Push a node to linked list. Note that this function 
  changes the head */
void push(Node** head_ref, char new_data) 
{ 
    /* allocate node */
    Node* new_node = (Node*)malloc(sizeof(Node)); 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to pochar to the new node */
    (*head_ref) = new_node; 
} 
  
// A utility function to print a given linked list 
void printList(Node* ptr) 
{ 
    while (ptr != NULL) { 
        printf("%c->", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 
  
/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 
    char str[] = "abacaba"; 
    int i; 
  
    for (i = 0; str[i] != '\0'; i++) { 
        push(&head, str[i]); 
        printList(head); 
        isPalindrome(head) ? printf("Is Palindrome\n\n") : printf("Not Palindrome\n\n"); 
    } 
  
    return 0; 
} 