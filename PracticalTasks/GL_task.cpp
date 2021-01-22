#include <iostream>
#define n 256

const void* string_in(const char* str1, const char* str2)
{
    const char* tmp_str = strstr(str1, str2);
    if (tmp_str != nullptr)
        return tmp_str;
    return nullptr;
}

int main()
{
    char word1[n];
    char word2[n];
    std::cin.getline(word1, n);
    std::cin.getline(word2, n);
    std::cout << string_in(word1, word2) << std::endl;

    return 0;
}
