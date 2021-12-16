/**
 * @file
 * @brief Engine source file
 * @authors Vorotnikov Andrey
 *
 * Contains engine class
 */

#include "engine.h"

/// @brief Add command to engine
/// @param[in] wrapper Function wrapper
/// @param[in] commandName Function name in engine
void Engine::RegCommand(Wrapper *wrapper, const std::string &commandName)
{
     if (wrapper == nullptr)
          return;
     commands_[commandName] = wrapper;
}

/// @brief Execute command
/// @param[in] commandName Name of command to execute
/// @param[in] args Argument map
/// @throw std::exception Unknown command
/// @return Function result
int Engine::Execute(const std::string &commandName, const std::map<std::string, int> &args)
{
     auto wrapperIt = commands_.find(commandName);
     if (commands_.end() == wrapperIt)
          throw std::exception("Unknown command");
     return (*wrapperIt->second)(args);
}
