//
// Created by Gideon Tonkinson on 10/25/21.
//

#ifndef PROJECT_3_HEADER_H
#define PROJECT_3_HEADER_H
#include <vector>
#include <string>

class Header {
private:
    std::vector<std::string> attributes;
public:
    Header();
    void addAttributes(std::string a);
    std::vector<std::string> getAttributes();
    std::string at(int i);
    size_t size();
};


#endif //PROJECT_3_HEADER_H
