#include <iostrem>

int ** makeMass(int ** Mass, size_t m, size_t n)
{
  //chto-to
}

int ** transpone(int ** Mass, size_t m, size_t n)
{

}

void rmMtx(int ** Mass, m)
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
  makeMass(Mass, m, n);


  for (size_t i = 0; i < m*n; i++)
  {
    std::cin >> Mass[i/m][i%m];
  }

  Mass = transpone();

  for (size_t i = 0; i < m*n; i++)
  {
    std::cout << Mass[i/m][i%m] << " ";
  }
}
