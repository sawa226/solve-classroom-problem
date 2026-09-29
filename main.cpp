#include <iostrem>

void rmMtx(int ** Mass, int m)
{ 
  for (size_t i = 0; i < m; i++)
  {
    delete [] mtx[i];
  }
  delete [] mtx;
}


int ** makeMass(size_t m, size_t n)
{
  try
  {
    int ** Mass = new int * [m];
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
}


int main() 
{
  size_t n = 0;
  size_t m = 0;
  std::cin >> n >> m;
  if (!std::cin)
  {
    return 1;
  }
  int ** Mass = nullptr;
  Mass = makeMass(Mass, m, n);

  for (size_t i = 0; i < m*n; i++)
  {
    std::cin >> Mass[i%m][i/m];
  }
  if (!std::cin) {
    return 1;
  }
  Mass = transpone();

  std::cout << Mass[0][0];
  for (size_t i = 1; i < m; i++)
  {
    std::cout << " " << Mass[0][i];
  }

  for (size_t i = 1; i < n; i++)
  {
    std::cout << '\n' << Mass[i][0];
    for (size_t j = 1; j < m; j++)
    {
      std::cout << " " << Mass[i][j]; 
    }
  }
  std::cout << "\n";
}
