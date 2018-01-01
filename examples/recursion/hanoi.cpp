using namespace std;

#include <iostream>

void MoveTowers(int n, int start, int finish, int spare);

main()
{
  int n;
 
  cout << "Enter number of disks to move: ";
  cin >> n;

  MoveTowers(n,1,3,2);

}

void MoveTowers(int n, int start, int finish, int spare)
{
  if (n == 1)
    cout << "Move a disk from peg " << start << " to " << finish << endl;
  else
  {
    MoveTowers(n-1,start,spare,finish);
    cout << "Move a disk from peg " << start << " to " << finish << endl;
    MoveTowers(n-1,spare,finish,start);
  }
}
