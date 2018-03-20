#include <kaspar/Proxied/proxied.hpp>
#include <vector>

void f(double) {
}

int main(void) {
  std::vector<kaspar::proxy_value<int>> m({1,2});
  int a = 3 * m[0];
  f(m[0]);
  m[0] = 2;
  return 0;
}
