#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Student
{ int id; double GPA;};

ostream & operator<<(ostream & out, const Student & s)
{ out << " id = " << s.id << "  GPA = " << s.GPA;
  return out;
}

bool operator<(const Student & a, const Student & b)
{ return a.id < b.id; }

int main()
{
  typedef map<string, Student, less<string> > map1;
  typedef map<Student, string, less<Student> > map2;

  map1 a1;   // associative array of Student, index type is string
  map2 a2;   // associative array of string, index type is Student

  Student s;
  s.id = 12345; s.GPA = 3.3;  a1["Fred"] = s;   a2[s] = "Fred";
  s.id = 32322; s.GPA = 3.9;  a1["Al"] = s;     a2[s] = "Al";
  s.id = 13131; s.GPA = 2.5;  a1["Joan"] = s;   a2[s] = "Joan";
  s.id = 22121; s.GPA = 4.0;  a1["Barb"] = s;   a2[s] = "Barb";
  s.id = 28888; s.GPA = 2.9;  a1["George"] = s; a2[s] = "George";
  s.id = 19981; s.GPA = 3.0;  a1["Dot"] = s;    a2[s] = "Dot";
  s.id = 20012; s.GPA = 2.9 ; a1["Sue"] = s;    a2[s] = "Sue";

  string name;
  cout << "Enter a name: ";
  cin >> name;
  map1::iterator it1 = a1.find(name);
  cout << name << " has ";
  if (it1== a1.end())
    cout << "no info";
  else
    cout << a1[name];
  cout << endl;

  Student aStudent;
  cout << "Enter an id and a GPA: ";
  cin >> aStudent.id >> aStudent.GPA;
  map2::iterator it2 = a2.find(aStudent);
  cout << "Student " << aStudent << " is ";
  if (it2 == a2.end())
    cout << "no info";
  else
    cout << a2[aStudent];
  cout << endl;
}
