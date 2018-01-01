void BTree::Level()
{
  BTree *queue[MAX];
  BTree *temp;
  int front = 0;
  int back = 0;

  queue[back++] = this;

  while (front != back)
  {
    temp = queue[front];
    front = (front + 1) % MAX;
    if (temp != NULL)
    {
      cout << temp->data << " ";
      queue[back] = temp->left;
      back = (back + 1) % MAX;
      queue[back] = temp->right;
      back = (back + 1) % MAX;

    }
  }
}
