#include <iostream>
#include "commonfile.hpp"

int main(int argc, const char* argv[]) {

    CommonFile cf;
    CommonEvent cev;

    cev.color = green;
    cev.name = "cool cev";
    cev.memo = "check out this awesome move";

    cev.a_arith(1600000, 1, 2, div_eq, op_times);

    cf.add_common(&cev);
    cf.generate("test.common");

    return 0;
}