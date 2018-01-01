using namespace std;
#include <iostream>
#include <cstdlib>

#include "queue.h"

// --- default constructor
Queue::Queue(int s)    
{
  if (s > MAX_QUEUE)
    {
      max_size = MAX_QUEUE;
      cout << "Error: queue size too big, setting to " << MAX_QUEUE << endl;
    }
  max_size = s > 0 ? s : 100;
  num_items = 0;
  back = front = max_size-1;
  queue_items = new int[max_size];
}

Queue::~Queue(void)
{
  delete queue_items;
}

int Queue::Empty(void)
{
  return(num_items == 0);
}

int Queue::Full(void)
{
  return(num_items == max_size);
}

void Queue::Insert(int item)
{
  // --- check for overflow
  if (Full())
    {
      cout << "Queue overflow" << endl;
      exit(1);
    }
  queue_items[back] = item;
  back = (back+1)%max_size;
  num_items++;
}

int Queue::Remove(void)
{
  int temp;

  if (Empty())
    {
      cout << "queue underflow" << endl;
      exit(1);
    }
  temp = queue_items[front];
  front = (front+1)%max_size;
  num_items--;
  return(temp);

}
