/**
 * Convenience enums for calculating various flag values.
*/

#pragma once

enum assign_type {
    eq          = 0x000,
    plus_eq     = 0x100,
    minus_eq    = 0x200,
    times_eq    = 0x300,
    div_eq      = 0x400,
    mod_eq      = 0x500
};

enum arith_op {
    plus        = 0x0000,
    minus       = 0x1000,
    times       = 0x2000,
    div         = 0x3000,
    mod         = 0x4000,
    bitwise_and = 0x5000
};