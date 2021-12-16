/**
 * @file
 * @brief Wrapper source file
 * @authors Vorotnikov Andrey
 *
 * Contains function wrapper class
 */

#include <map>
#include <string>

#include "wrapper.h"

/// @brief Operator for functor
/// @param[in] args Arguments map
/// @return Instanse method result
int Wrapper::operator()(const std::map<std::string, int> &args)
{
     return method_(ExtractArgs(args));
}

/// @brief Create arguments vector
/// @param[in] args Arguments map
/// @return Arguments vector
std::vector<int> Wrapper::ExtractArgs(const std::map<std::string, int> &args)
{
     std::vector<int> extractedArgs;
     extractedArgs.reserve(defaultArgs_.size());
     for (auto it = defaultArgs_.begin(); it != defaultArgs_.end(); ++it)
     {
          auto findedIt = args.find(it->first);
          if (args.end() != findedIt)
               extractedArgs.push_back(findedIt->second);
          else
               extractedArgs.push_back(it->second);
     }
     return extractedArgs;
}
