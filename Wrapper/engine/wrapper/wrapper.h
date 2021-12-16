/**
 * @file
 * @brief Wrapper header file
 * @authors Vorotnikov Andrey
 *
 * Contains function wrapper class
 */

#pragma once

#ifndef __WRAPPER_H_INCLUDED
#define __WRAPPER_H_INCLUDED

#include <map>
#include <string>
#include <vector>
#include <functional>

/// @brief Wrapper represenation type
class Wrapper
{
public:
     /// @brief Constructor
     /// @param[in] instance Class instance
     /// @param[in] method Class method
     /// @param[in] args Default arguments
     template<typename T, typename... Args>
     Wrapper(T *instance, int (T::*method)(Args...), const std::vector<std::pair<std::string, int>> &args)
     {
          if (instance == nullptr || method == nullptr || args.size() != sizeof...(Args))
               return;
          defaultArgs_ = args;

          method_ = [instance, method](const std::vector<int> &extractArgs)
          {
               return CallFunction(instance, method, extractArgs, std::make_index_sequence<sizeof...(Args)>{});
          };
     }

     /// @brief Operator for functor
     /// @param[in] args Arguments map
     /// @return Instanse method result
     int operator()(const std::map<std::string, int> &args);

private:
     /// @brief Default arguments array
     std::vector<std::pair<std::string, int>> defaultArgs_;

     /// @brief Wrapped method
     std::function<int(const std::vector<int> &)> method_;

     /// @brief Create arguments vector
     /// @param[in] args Arguments map
     /// @return Arguments vector
     std::vector<int> ExtractArgs(const std::map<std::string, int> &args);

     /// @brief Constructor
     /// @param[in] instance Class instance
     /// @param[in] method Class method
     /// @param[in] extractArgs Arguments method
     /// @param[in] Indecies Index sequence
     /// @return Instanse method result
     template<typename T, typename Function, size_t... Indecies>
     static int CallFunction(T *instance, Function method, const std::vector<int> &extractArgs, std::index_sequence<Indecies...>)
     {
          return ((instance->*method)(extractArgs[Indecies]...));
     }
};

#endif // !__WRAPPER_H_INCLUDED
