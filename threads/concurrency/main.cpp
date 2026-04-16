// #include <iostream>
#include <MemoryMapFile.hpp>
#include <LineReader.hpp>
#include <iostream>
#include <string_view>

int main(){
    MemoryMapFile mapped_file("larger_file");
    char * r = NULL;
    while ((r = mapped_file.read())){
    std::cout << mapped_file.readed_length << "\n";
        
    }

    std::cout << mapped_file.eof << "\n";
    std::cout << mapped_file.readed_length << "\n";
    std::cout << mapped_file.get_file_size() << "\n";

}