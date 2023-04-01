#include <regex>
#include <iterator>
#include <iostream>
#include <string>
 
int main()
{
    const std::string s = "nv_n65@hbnh.khjj Quick bro56wn fo22x g545g-gg@jb.mb.thmjrhmj. nvn@hbnh @vnhvhv.vng @hvnmhg hghj.g767@hjbmj.jnj";
 
    std::regex words_regex("[a-z\\dA-Z\\._-]+@([a-z\\.]+\\.[a-z]+)");
    auto words_begin = 
        std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();
 
    std::cout << "Found " 
              << std::distance(words_begin, words_end) 
              << " emails:" << std::endl;
 
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;                                                 
        std::string match_str = match.str(); 
        std::cout << match_str << " " << match[1].str() << std::endl;
    }   
}