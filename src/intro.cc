// An introduction to the wonders of the Baseball Design Pattern.
//
// One rule: never return.
//
// You may only throw and catch.

#include <iostream>

#include "catch_main.h"

// Factorial
void factorial(int n, int accum = 1) { // throw(int)
  if (n == 0) throw accum;
  factorial(n - 1, n * accum);
}

// Null terminated string length
void string_length(const char* str, int accum = 0) { // throw(int)
  if (*str == '\0') throw accum;
  string_length(str + 1, accum + 1);
}

// Convert a string to an integer, assuming decimal encoding. Throw a false bool if no integer is encountered.
void string_to_int(const char* str) { // throw(int, bool)
  bool got_num = false;
  int sign = 1;
  int value = 0;
  if (*str) {
    if (*str == '-') { sign = -1; ++str; }
    while (*str >= '0' && *str <= '9') {
      got_num = true;
      value *= 10;
      value += *str - '0';
      str++;
    }
  }
  if (got_num) throw value * sign;
  throw false;
}

// The usual main function is replaced with catch_main, as defined in catch_main.h.
void catch_main(int argc, char** argv) {
  try { factorial(4); }
  catch (int result) {
    std::cout << "The factorial of 4 is " << result << std::endl;
  }

  try { string_length("hello, world"); }
  catch (int length) {
    std::cout << "The length of 'hello, world' is " << length << std::endl;
  }

  try { string_to_int("12345"); }
  catch (int value) {
    std::cout << "The value of string '12345' is " << value << std::endl;
  }
  catch (bool failure) {
    std::cout << "The value was not a integer" << std::endl;
  }

  try { string_to_int("Letters"); }
  catch (bool success) {
    std::cout << "The value of string 'Letters' could not be converted to an int" << std::endl;
  }

  throw 0;
}
