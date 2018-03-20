#pragma once
#include <iostream>

namespace kaspar {

template <typename Container>
class Proxied : public Container {
public:
  typedef typename Container::value_type value_type;
  struct proxy_value {
    value_type* data;
    proxy_value(void)=delete;
    proxy_value(proxy_value const& other) {
      data = other.data;
    }
    proxy_value(value_type& el) : data(&el) {}
    operator value_type() {
      std::cout << "read operation" << std::endl;
      return *data;
    }
    proxy_value& operator=(proxy_value const& other) {
      std::cout << "read and write operation" << std::endl;
      *data = *other.data;
      return *this;
    }
    proxy_value& operator=(value_type const& val) {
      std::cout << "write operation" << std::endl;
      *data = val;
      return *this;
    }
  };

  Proxied(Container const& c) : Container(c) {}
  Proxied(Container&& c) : Container(c) {}
  Proxied(void) : Container() {}
  Proxied(Proxied<Container> const& other) : Container(other) {}
  Proxied(Proxied<Container>&& other) : Container(other) {}

  proxy_value operator[](size_t ind) {
    return proxy_value(Container::operator[](ind));
  }
};

} // kaspar
