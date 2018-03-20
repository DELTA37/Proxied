#include <kaspar/Proxied/proxied.hpp>
#include <vector>

void f(double) {
}

int main(void) {
  kaspar::Proxied<std::vector<int>> m({1,2});
  m.push_back(1);
  int a = 3 * m[0];
  f(m[0]);
  m[0] = 2;
  return 0;
}
