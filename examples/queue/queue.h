/*************************************************************
 *
 *   NAME: Brother Cameron
 *
 *   FILE: queue.h
 *
 *   PURPOSE: Class definition for a queue (arrays)
 *
 *************************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H

using namespace std;
#include <iostream>

#define MAX_QUEUE 500

class Queue
{
 private:
  int front;               // --- index of front of queue
  int back;                // --- index of back of queue
  int max_size;            // --- max storage capacity of array
  int num_items;           // --- number of items currently in queue
  int *queue_items;        // --- array containing queue items
  
 public:
  Queue(int = 100);        // --- constructor
  ~Queue(void);            // --- destructor
  void Insert(int item);   // --- insert item into back of queue
  int Remove(void);        // --- remove item into front of queue
  int Empty(void);         // --- returns 1 if queue is empty, 0 otherwise
  int Full(void);          // --- returns 1 if queue is full, 0 otherwise
};

#endif
