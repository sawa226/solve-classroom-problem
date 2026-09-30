#include "convertFunc.h"

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  int ** Mass = new int * [rows];
  try
  {
    for (size_t i = 0; i < rows; i++)
    {
      Mass[i] = new int [lns[i]];
      
    } 
  }
}
