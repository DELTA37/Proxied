#pragma once
#include <iostream>

namespace kaspar {

template <typename value_type>
class proxy_value {
public:
  proxy_value(void) {
    data = new value_type();
  }
  proxy_value(proxy_value<value_type> const& other) {
    data = new value_type(*other.data);
  }
  proxy_value(value_type const& el) {
    data = new value_type(el);
  }
  proxy_value(value_type& el) : data(&el) {}
  operator value_type() {
    std::cout << "read operation" << std::endl;
    return *data;
  }
  proxy_value<value_type>& operator=(proxy_value<value_type> const& other) {
    std::cout << "read and write operation" << std::endl;
    *data = *other.data;
    return *this;
  }
  proxy_value<value_type>& operator=(value_type const& val) {
    std::cout << "write operation" << std::endl;
    *data = val;
    return *this;
  }
  virtual ~proxy_value(void) {
    delete data;
  }
private:
  value_type* data;
};


} // kaspar
