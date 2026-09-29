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

int transpone(int ** Mass, size_t m, size_t n)
{
  return 1;
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
  Mass = makeMass(m, n);

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
  std::cout << "\n";
}
