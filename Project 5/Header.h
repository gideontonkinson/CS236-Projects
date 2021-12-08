//
// Created by Gideon Tonkinson on 10/25/21.
//

#ifndef PROJECT_3_HEADER_H
#define PROJECT_3_HEADER_H
#include <vector>
#include <string>
#include <map>

class Header {
private:
    std::vector<std::string> attributes;
public:
    Header() = default;
    void addAttributes(std::string a);
    Header* combineHeader(Header* h, const std::map <size_t, size_t> &m);
    std::vector<std::string> getAttributes();
    std::string at(int i);
    size_t size();
};


#endif //PROJECT_3_HEADER_H
