/**
 * @file
 * @brief Main program source file
 * @authors Vorotnikov Andrey
 *
 * Contains main function to start program
 */

#include <iostream>

#include "engine/engine.h"

namespace
{

/// @brief Arithmetic operations class
class Arithmetic
{
public:
     /// @brief Integer sum
     /// @param[in] x First term
     /// @param[in] y Second term
     /// @return sum
     int sum(int x, int y)
     {
          return x + y;
     }

     /// @brief Integer difference
     /// @param[in] x Minuend
     /// @param[in] y Subtrahend
     /// @return difference
     int dif(int x, int y)
     {
          return x - y;
     }
};

/// @brief Increment class
class Incrementor
{
public:
     /// @brief Constructor
     /// @param[in] iniVal Value to start
     Incrementor(int iniVal = 0) : val_(iniVal)
     {
     }

     /// @brief Incrementation
     /// @param[in] valToIncrement Value to increment
     /// @return incrementated value
     int inc(int valToIncrement)
     {
          val_ += valToIncrement;
          return val_;
     }

private:
     int val_;
};

}

/// @brief Main program function
/// @return Code to OS
int main()
{
     Engine engine;

     Arithmetic arithmetic;
     Incrementor incrementor;

     try
     {
          std::cout << engine.Execute("Incorrect", {}) << std::endl;
     }
     catch (...)
     {
          std::cout << "Unregistrated command" << std::endl;
     }

     Wrapper sum(&arithmetic, &Arithmetic::sum, {{"x", 0}, {"y", 0}});
     Wrapper dif(&arithmetic, &Arithmetic::dif, {{"y", 1}, {"x", 0}});
     Wrapper inc(&incrementor, &Incrementor::inc, {{"step", 1}});

     engine.RegCommand(&sum, "sum");
     engine.RegCommand(&dif, "dif");
     engine.RegCommand(&inc, "inc");

     std::cout << "Sum(1, 2): " << engine.Execute("sum", {{"x", 1}, {"y", 2}}) << " == 3" << std::endl;
     std::cout << "Sum(0, 1): " << engine.Execute("sum", {{"y", 1}}) << " == 1" << std::endl;
     std::cout << "Mul(3, 2): " << engine.Execute("dif", {{"x", 4}, {"y", 2}}) << " == -2" << std::endl;
     std::cout << "Mul(1, 1): " << engine.Execute("dif", {}) << " == 1" << std::endl;
     std::cout << "Inc(-1): " << engine.Execute("inc", {{"step", -1}}) << " == -1" << std::endl;
     std::cout << "Inc(10): " << engine.Execute("inc", {{"step", 10}}) << " == 9" << std::endl;

     return 0;
}
