#include "commonfile.hpp"

int main(int argc, const char* argv[]) {

    CommonFile cf;
    CommonEvent cev;

    cev.color = green;
    cev.name = "cool cev";
    cev.memo = "check out this awesome move";
    
    Line l;
    l.int_fields = {106};
    l.str_fields = {"hello world"};
    cev.lines.push_back(l);

    cf.add_common(&cev);
    cf.generate("test.common");

    return 0;
}