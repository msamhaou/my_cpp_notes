#pragma once
#include <MemoryMapFile.hpp>
#include <optional>

class LineReader{
private: 
    MemoryMapFile&  mapped_file;
    int             readed_bytes;
    static int      all_readed;
public:
    static std::string     remaining;
    LineReader( MemoryMapFile &_mapped_file);
    std::optional<std::string> read_line();
};