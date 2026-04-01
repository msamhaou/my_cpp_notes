#pragma once
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <err.h>
#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

class MemoryMapFile{
private:
    void *          addr;
    int             fd;
    size_t          length;
    unsigned int    offset;
    size_t          file_size;
    size_t          page_len;
    void            set_size_file(const int & fd);
    char*           buffer;
public:
    bool            eof;
    MemoryMapFile( std::string filename );
    ~MemoryMapFile();
    char * read();
    size_t get_file_size();
    size_t get_length();
    char * get_addr();
};