// RUN: %clang_cc1 -fsyntax-only -verify %s
template <typename T> struct S {
  S() { }
  S(T t);
};

template struct S<int>;

void f() {
  S<int> s1;
  S<int> s2(10);
}

namespace PR7184 {
  template<typename T>
  void f() {
    typedef T type;
    void g(int array[sizeof(type)]);
  }

  template void f<int>();
}
