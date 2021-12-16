/**
 * @file
 * @brief Engine header file
 * @authors Vorotnikov Andrey
 *
 * Contains engine class
 */

#pragma once

#ifndef __ENGINE_H_INCLUDED
#define __ENGINE_H_INCLUDED

#include "wrapper/wrapper.h"

/// @brief Engine represenation type
class Engine
{
public:
     /// @brief Add command to engine
     /// @param[in] wrapper Function wrapper
     /// @param[in] commandName Function name in engine
     void RegCommand(Wrapper *wrapper, const std::string &commandName);

     /// @brief Execute command
     /// @param[in] commandName Name of command to execute
     /// @param[in] args Argument map
     /// @throw std::exception Unknown command
     /// @return Function result
     int Execute(const std::string &commandName, const std::map<std::string, int> &args);

private:
     /// @brief Registated commands
     std::map<std::string, Wrapper *> commands_;
};

#endif // !__ENGINE_H_INCLUDED
