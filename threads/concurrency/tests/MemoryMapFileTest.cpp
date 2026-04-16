
#include <gtest/gtest.h>
#include <MemoryMapFile.hpp>

TEST(MemoryMapFileTest, OpensFileSuccessfully){
    MemoryMapFile file("test_file/larger_file");
    file.read();
    int len = std::string("Lorem").length();

    std::string first_word = std::string(file.get_addr(), len);

    EXPECT_EQ(first_word, "Lorem");
}

TEST(MemoryMapFileTest, ThrowsExceptionWhenFileDoesNotExist){
    std::string non_existent_file = "test_file/non_existent_file.txt";
    EXPECT_THROW(
        {
            MemoryMapFile file(non_existent_file);
        },
        std::runtime_error
    );
}