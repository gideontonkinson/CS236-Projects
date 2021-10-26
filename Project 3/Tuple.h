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
    bool operator< (const Tuple &rhs) const;
};


#endif //PROJECT_3_TUPLE_H
