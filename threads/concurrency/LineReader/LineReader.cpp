#include <LineReader.hpp>

LineReader::LineReader(MemoryMapFile & _mapped_file): mapped_file(_mapped_file), readed_bytes(0){

}

std::string LineReader::remaining = "";
int LineReader::all_readed = 0;

std::optional<std::string> LineReader::read_line(){

    const char * addr = this->mapped_file.get_addr();
    int count = this->readed_bytes;
    int start = this->readed_bytes;
    
    if (count >= this->mapped_file.get_length())
        return std::nullopt;
    if (addr[count] == '\n'){
        this->readed_bytes += 1;
        LineReader::all_readed += 1;
        return "";
    }
    while(count < this->mapped_file.get_length() && addr[count] != '\n' && !this->mapped_file.eof){
        count++;
    }
    LineReader::all_readed += count;

    if (LineReader::all_readed == this->mapped_file.get_file_size())
        std::cout << "end reached\n";

    if (count == mapped_file.get_length() && addr[count - 1] != '\n' && this->readed_bytes != mapped_file.get_file_size()){
            this->remaining = std::string(addr + start, count - start);
            return std::nullopt;
        }
        
    this->readed_bytes = count + 1;
    if (addr[count] == '\n' || this->readed_bytes == mapped_file.get_file_size()){
        if (!remaining.empty()){
            std::string res =  std::move(this->remaining) + (std::string(addr + start, count - start));
            return res;
        }
        std::string res = (std::string(addr + start, count - start));
        return res;
    }

    return "";
}