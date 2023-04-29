#ifndef FUNCTIONPOINTER_HPP_
    #define FUNCTIONPOINTER_HPP_

#include <unordered_map>
#include <functional>
#include <iostream>

class FunctionPointer {
    public:
        FunctionPointer() = default;
        ~FunctionPointer() = default;
        void executeCommand(const std::string &command);
        static void print();
    private:
        std::unordered_map<std::string, std::function<void()>> commands{{"-p", [&]() {FunctionPointer::print();}}};
};

#endif /* !FUNCTIONPOINTER_HPP_ */
