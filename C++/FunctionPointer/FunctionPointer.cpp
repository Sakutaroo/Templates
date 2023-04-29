#include "FunctionPointer.hpp"

void FunctionPointer::executeCommand(const std::string &command)
{
    if (this->commands.count(command) == 0) {
        std::cout << "Unknown command, but it's normal...\n";
        return;
    }
    this->commands[command]();
}

void FunctionPointer::print()
{
    std::cout << "Hello World!" << std::endl;
}
