#include <iostream>
#include <fstream>
#include <thread>

void writeToFile() {
    std::ofstream file("E:/File_txt/dulieu.txt", std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Cannot open dulieu.txt!" << std::endl;
        return;
    }
    char ch;
    std::cout << "Enter char : " << std::endl;
    while (true) {
        std::cin >> ch;
        if (ch == '!') {
            std::cout << "End !" << std::endl;
            break; 
        }
        file << ch;
    }
    file.close();
}

int main() {
    std::thread writerThread(writeToFile);
    writerThread.join();
    std::cout << "Successfull Process" << std::endl;
    return 0;
}
