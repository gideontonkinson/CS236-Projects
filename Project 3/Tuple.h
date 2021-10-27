//
// Created by Gideon Tonkinson on 10/25/21.
//

#ifndef PROJECT_3_TUPLE_H
#define PROJECT_3_TUPLE_H
#include <vector>
#include <string>


class Tuple {
private:
    std::vector<std::string> values;
public:
    Tuple() = default;
    void addValue(std::string newVal);
    bool operator< (const Tuple& rhs) const;
    std::string at(int i);
    size_t size();
};


#endif //PROJECT_3_TUPLE_H
