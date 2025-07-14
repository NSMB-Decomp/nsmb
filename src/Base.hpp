class Base {
public:
  bool a;
  char func();
  char poly_func();
  virtual char virt_func();
  Base();
  Base(bool);
};

class Based : public Base {
public:
  bool b;
  char poly_func();
  virtual char virt_func();
  Based();
};