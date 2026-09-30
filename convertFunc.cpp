#include "convertFunc.h"

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  int ** Mass = new int * [rows];
  try
  {
    int lenlns = 0;
    int k = 0;
    for (size_t i = 0; i < rows; i++)
    {
      lenlns = lns[i];
      Mass[i] = new int [lenlns];
      for (size_t j = 0; j < lenlns; j++)
      {
        Mass[i][j] = t[k];
        k++;
      }
    } 
    return Mass;
  } catch (std::bad_alloc & e)
  {
    for (size_t i = 0; i < rows; i++)
    {
      delete[] Mass[i];
    }
    delete[] Mass;
    throw;
  }
}
