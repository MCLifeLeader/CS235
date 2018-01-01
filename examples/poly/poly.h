/******************************************************************************
 *
 *  File: poly.h
 *
 *  Author: Brother Cameron, 10/9/2001
 *
 *  Purpose: Defines classes for a Term and a Polynomial
 *
 ******************************************************************************/
class Term
{
 private:
  float coeff;
  int expon;
 
 public:
  Term();                  // --- Creates empty Term
  Term(float c, int e);    // --- Creates Term object with coeff. c and expon. e
  float get_coeff(void);   // --- returns coeff of term
  int get_expon(void);     // --- returns expon of term
  void set_coeff(float c); // --- sets term's coeff. to c
  void set_expon(int c);   // --- sets term's expon to c
};

class Poly
{
 private:
  int num_terms;           // --- number of terms in polynomial
  int max_items;           // --- array capacity
  Term *terms;             // --- dynamically allocated array of terms

 public:
  Poly();                       // --- creates empty polynomial
  void Insert_Term(Term t);     // --- inserts Term t into polynomial
  float Eval(float x);          // --- evaluates polynomial with value x
  void PrintPoly(void);         // --- prints out polynomial
};
