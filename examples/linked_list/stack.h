/*******************************************************************
 *
 *     FILE: list.h
 *
 *  PURPOSE: Contains the class definition of a Node and a List
 *
 *******************************************************************/
class Node
{
 private:
  int data;                // --- data in each node
  Node *next;              // --- pointer to next node

 public:
  Node();                  // --- Creates empty node
  ~Node();                 // --- Deletes node
  Node *get_next();        // --- returns next pointer of a node
  int get_data();          // --- returns data of a node
  void set_data(int item); // --- stores item in data member of current node
  void set_next(Node *node); // --- sets next to point to node
};

class Stack
{
 private:
  int num_items;          // --- number of items in stack
  Node *stack_items;      // --- pointer to top of stack
  
 public:
  Stack();
  ~Stack();
  void Push(Node n);
  Node *TopOfStack(void);
  void Pop(void);
  int Empty(void);
}




