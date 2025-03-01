#include <iostream>
#include <fstream>

int main() {
    std::ifstream pipe("my_pipe");  // Open named pipe for reading
    if (!pipe) {
        std::cerr << "Error opening pipe for reading\n";
        return 1;
    }

    std::string message;
    std::getline(pipe, message);
    std::cout << "Received: " << message << std::endl;

    return 0;
}
