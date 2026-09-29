#include <iostream>

void remove(int ** Mass, int m)
{ 
  for (size_t i = 0; i < m; i++)
  {
    delete [] Mass[i];
  }
  delete [] Mass;
}


int ** makeMass(size_t m, size_t n)
{
  int ** Mass = new int * [m];
  try
  {
    for (size_t i = 0; i < m; i++)
    {
      Mass[i] = new int [n];
    }
  } catch (const std::bad_alloc & e)
  {
    remove(Mass, m);
    throw;
  }
  return Mass;
}

int ** transpone(int ** Mass, size_t m, size_t n)
{
  int ** Mass2 = nullptr;
  try
  {
    Mass2 = makeMass(n,m);
  } catch (const std::bad_alloc & e)
  {
    throw;
  }
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      Mass2[i][j] = Mass[j][i];
    }
  }
  return Mass2;
}

void vivod(int ** Mass, size_t m, size_t n)
{ 
  std::cout << Mass[0][0];
  for (size_t i = 1; i < n; i++)
  {
    std::cout << " " << Mass[0][i];
  }

  for (size_t i = 1; i < m; i++)
  {
    std::cout << '\n' << Mass[i][0];
    for (size_t j = 1; j < n; j++)
    {
      std::cout << " " << Mass[i][j]; 
    }
  }
}

int main() 
{
  size_t n = 0;
  size_t m = 0;
  std::cin >> m >> n;
  if (!std::cin)
  {
    return 1;
  }
  int ** Mass = nullptr;
  try
  {
  Mass = makeMass(m, n);
  } catch (const std::bad_alloc & e)
  {
    return 2;
  }
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      std::cin >> Mass[i][j];
    }
  }
  if (!std::cin) {
    return 1;
  }
  
  try
  {
    Mass = transpone(Mass, m, n);
  } catch (const std::bad_alloc & e)
  {
    return 2;
  }
  vivod(Mass, n, m);
}
