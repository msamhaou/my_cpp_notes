#include <LineReader.hpp>

LineReader::LineReader(MemoryMapFile & _mapped_file): mapped_file(_mapped_file), readed_bytes(0){

}

static void test(const char * addr){

    std::cout << std::string (addr, 5) << "\n";;
}

// std::string get_remaining(char * addr){
//     if (count == mapped_file.get_length() && !mapped_file.eof && addr[count] !="\n"){
//         this->remaining = std::string(addr + start, count);
//         return std::nullopt;
//     }
// }

std::optional<std::string> LineReader::read_line(){

    const char * addr = this->mapped_file.get_addr();
    int count = this->readed_bytes;
    int start = this->readed_bytes;
    if (count >= this->mapped_file.get_length())
        return std::nullopt;
    if (addr[count] == '\n'){
        this->readed_bytes += 1;
        return "";
    }
    while(count < this->mapped_file.get_length() && addr[count] != '\n'){
        count++;
    }
    if (count == mapped_file.get_length() && addr[count - 1] != '\n'){
            this->remaining = std::string(addr + start, count - start);
            return std::nullopt;
        }
        
    this->readed_bytes = count + 1;
    if (addr[count] == '\n'){
        if (!remaining.empty()){
            std::string res =  std::move(this->remaining) + (std::string(addr + start, count - start));
            return res;
        }
        std::string res = (std::string(addr + start, count - start));
        return res;
    }

    return "";
}