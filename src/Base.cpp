#include "Base.hpp"

char Base::func() {
  this->a = true;
  return 1;
}

char Base::poly_func() {
  this->a = false;
  return 0;
}

char Base::virt_func() {
  this->a = false;
  return 0;
}


char Based::poly_func() {
  this->a = false;
  this->b = true;
  return 1;
}

char Based::virt_func() {
  this->a = false;
  this->b = true;
  return 1;
}

Base::Base() {
  this->a = false;
}
Base::Base(bool a) {
  this->a = a;
}

Based::Based() {
  this->b = false;
}

int main() {
  Base base;
  Based not_base;
  base.func();
  base.poly_func();
  base.virt_func();
  not_base.func();
  not_base.poly_func();
  not_base.virt_func();
};