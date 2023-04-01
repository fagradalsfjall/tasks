#include <regex>
#include <iterator>
#include <iostream>
#include <string>
 
int main()
{
    const std::string s = "br2333.07.18o56wn fo22x g545g-gg@jb.mb.thmjrhmj. \
    nvn@hbnh @vnhvhv.vng @hvnmhg hghj.g767@hjbmj.jnj\
    4532.00.12 5455.77.13 5435.11.24\
    11:55:16 323:11:11 00:00:00 01:59:60";
 
    std::regex words_regex("(\\d\\d\\d\\d\\.(0[1-9]|1[0-2]).(0[1-9]|[1-2][0-9]|3[0-1]))\
|((0[0-9]|1[0-2]|2[0-3]):([0-5][0-9]):([0-5][0-9]))");
    auto words_begin = 
        std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();
 
    std::cout << "Found " 
              << std::distance(words_begin, words_end) 
              << " dates:" << std::endl;
 
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;                                                 
        std::string match_str = match.str(); 
        std::cout << match_str << std::endl;
    }   
}