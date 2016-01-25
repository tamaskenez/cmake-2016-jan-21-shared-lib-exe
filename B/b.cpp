#include <iostream>

#include "a.hpp"
#include "b.hpp"

int bar () {
  foo ();
  std::cout << "This is bar!" << std::endl;
  return 0;
}

