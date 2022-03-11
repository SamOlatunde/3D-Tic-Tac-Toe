// stack definition file file

struct Node 
{
  char data;
  Node * next;

  Node (char c)
  {
    data = c;
    next = NULL;
  }
};

class Stack
{
  private:
  Node * head;
  int size;

  public:
  Stack ();
  void push(char c);
  char pop();
  char peek();
  void print();
  int Size();
  

};