#pragma once

#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#define EPSILON 0.00001  // точность для сравнения числе с плавающей точкой

#define SETUP_TESTS() munit::TestRunner test_runner
#define ASSERT(expected, hint)                                            \
  munit::AssertEqual(expected, true, hint, __LINE__, __FILE__, #expected, \
                     "true")
#define ASSERT_EQ(expected, actual, hint)                                   \
  munit::AssertEqual(expected, actual, hint, __LINE__, __FILE__, #expected, \
                     #actual)
#define ASSERT_EQ_FLOAT(expected, actual, hint)                           \
  munit::AssertEqual(expected, actual, EPSILON, hint, __LINE__, __FILE__, \
                     #expected, #actual)
#define RUN_TEST(test_case) test_runner.RunTest(test_case, #test_case)

namespace munit {
template <class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint, int line,
                 const char* file, const char* t_name, const char* u_name) {
  if (t != u) {
    std::ostringstream os;
    os << file << ":" << line << "\n  ";
    os << hint << "\n  ";
    os << "expected: " << t_name << " == " << u_name << ", but " << t
       << " != " << u;
    throw std::runtime_error(os.str());
  }
}

template <class T, class U, class E>
void AssertEqual(const T& t, const U& u, const E& epsilon,
                 const std::string& hint, int line, const char* file,
                 const char* t_name, const char* u_name) {
  auto diff = t - u;
  if (diff >= epsilon) {
    std::ostringstream os;
    os << file << ":" << line << "\n  ";
    os << hint << "\n  ";
    os << "expected: " << t_name << " == " << u_name << ", but " << t
       << " != " << u << " epsilon = " << epsilon;
    throw std::runtime_error(os.str());
  }
}

class TestRunner {
  int fail_count;

 public:
  TestRunner() : fail_count(0) {}

  template <class TestFunc>
  void RunTest(TestFunc func, const std::string& test_name) {
    try {
      func();
      std::cerr << test_name << " OK" << std::endl;
    } catch (std::runtime_error& e) {
      ++fail_count;
      std::cerr << "FAIL: " << test_name << "\n  " << e.what() << "\n\n"
                << std::endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
      std::exit(EXIT_FAILURE);
    }
  }
};

}  // namespace munit
