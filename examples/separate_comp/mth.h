class Mth
{
 private:
  int op1;
  int op2;
  int result;

 public:
  Mth();
  void Add();
  void Sub();
  void Mult();
  void Div();
  int get_result();
  void set_op1(int o1);
  void set_op2(int o2);
  int get_op1();
  int get_op2();
};

