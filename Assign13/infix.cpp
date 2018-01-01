void BTree::Infix()
{
  if (this != NULL)
  {
    left->Infix();
    cout << data << " ";
    right->Infix();
  }
}
