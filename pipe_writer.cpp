#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
    std::ofstream pipe("my_pipe");  // Open named pipe for writing
    if (!pipe) {
        std::cerr << "Error opening pipe for writing\n";
        return 1;
    }

    std::string message = "Hello from the C++ writer!";
    pipe << message << std::endl;
    std::cout << "Sent: " << message << std::endl;

    return 0;
}
