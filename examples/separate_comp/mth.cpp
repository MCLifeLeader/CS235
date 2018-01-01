#include "mth.h"

Mth::Mth()
{
  op1 = 0;
  op2 = 0;
  result = 0;
}

void Mth::Add()
{
  result = op1 + op2;
}

void Mth::Sub()
{
  result = op1 - op2;
}

void Mth::Mult()
{
  result = op1 * op2;
}

void Mth::Div()
{
  result = op1 / op2;
}

int Mth::get_op1()
{
  return op1;
}

int Mth::get_op2()
{
  return op2;
}

int Mth::get_result()
{
  return result;
}

void Mth::set_op1(int o1)
{
  op1 = o1;
}

void Mth::set_op2(int o2)
{
  op2 = o2;
}
