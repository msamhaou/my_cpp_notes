// #include <iostream>
#include <MemoryMapFile.hpp>
#include <LineReader.hpp>
#include <iostream>
#include <string_view>
int main(){
    MemoryMapFile m = MemoryMapFile(std::string("file"));
    char * r = m.read();

   std::string rr(r, m.get_length());

    LineReader lineReader = LineReader(m);

    std::optional<std::string> line = lineReader.read_line();
    while (line.has_value()){
        std::cout <<line.value() << "\n";
        line = lineReader.read_line();
    }

    std::cout << lineReader.remaining << "\n";
}