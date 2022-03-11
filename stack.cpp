// stack implementation file
#include <iostream>
#include "stack.h"
using namespace std;

// default constructor
Stack:: Stack ()
{
  head = NULL;
  size = 0;
}

// method to add new items to the top of the stack 
void Stack:: push(char c)
{

  // if our stack in this case is full. I used 4 instead of 3 because we initialized our stacks with blank spaces
 if (Size() ==4) 
 {
   cout << "Invalid Move!"<< endl;
 }
 else 
 {
   Node * temp = new Node(c);
  // if the list is empty
    if (head == NULL)
    {
      head = temp;
      size++;
    }
    else 
    {
      temp->next = head;
      head = temp;
      size++;
    }
      
 }
  
}

// method to remove and return the top of the stack
char Stack:: pop()
{
  // if the stack is empty
  if (head == NULL)
  {
    cout << "Gameboard is empty";
    return -1;
  }
  else 
  {

    Node * node_to_delete = head;
    char char_to_return =head->data;
    head = head->next;
    delete node_to_delete;
    node_to_delete = NULL;

    size --;
    return char_to_return;
  }
} 

//method that returns the top of the stack
char Stack:: peek()
{
  return head->data;
}

// method that prints the items in the stack 
void Stack::print()
{
  Node * traverse = head;
  while (traverse != NULL)
  {
    cout << traverse->data << endl;
    traverse = traverse->next;
  }
}

// method to return the number of items in the stack
int Stack:: Size()
{
  return size;
}
/*bool Stack:: isFull()
{
   
}*/