#include "catch_main.h"

#include <stdexcept>

int main(int argc, char** argv) {
  try { catch_main(argc, argv); } catch (int ret) { return ret; }
  throw std::runtime_error("catch_main did not throw. the ball was dropped.");
}
