#include <MemoryMapFile.hpp>

MemoryMapFile::MemoryMapFile(std::string filename): eof(false), addr(NULL){
    this->fd = open(filename.c_str(), O_RDONLY);
    this->page_len =  sysconf(_SC_PAGESIZE);
    this->length = this->page_len;
    this->offset = 0;
    this->set_size_file(this->fd);
}


MemoryMapFile::~MemoryMapFile(){
    munmap(this->addr,this->length);
    close(this->fd);
}
void MemoryMapFile::set_size_file(const int & fd){
    struct stat sb;
    if (fstat(fd, &sb))
        err(EXIT_FAILURE, "fstat");
    this->file_size = sb.st_size;
}



char * MemoryMapFile::read(){
    if (this->eof)
        return NULL;
    if (this->addr != MAP_FAILED && this->addr != NULL)
        munmap(this->addr, this->length);
    this->addr = mmap(NULL, this->length, PROT_READ, MAP_PRIVATE, this->fd, this->offset * this->page_len);
    if (this->length * this->offset >= this->file_size){
        this->length = this->file_size - (this->offset * this->page_len);
        this->eof = true;
    }
    this->offset += 1;
    return (char *)this->addr;
}

size_t MemoryMapFile::get_length(){
    return this->length;
}

char * MemoryMapFile::get_addr(){
    return (char * )this->addr;
}
