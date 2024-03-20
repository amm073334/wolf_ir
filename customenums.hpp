/**
 * Convenience enums for calculating various flag values.
*/

#pragma once

enum arith_flag {
    limit       = 0x01,
    jissuu      = 0x02,
    yobanai1    = 0x04,
    yobanai2    = 0x08,
    yob_store   = 0x10,
    yob_arg1    = 0x20,
    yob_arg2    = 0x40
};

enum assign_type {
    eq          = 0x000,
    plus_eq     = 0x100,
    minus_eq    = 0x200,
    times_eq    = 0x300,
    div_eq      = 0x400,
    mod_eq      = 0x500
};

enum arith_op {
    op_plus     = 0x0000,
    op_minus    = 0x1000,
    op_times    = 0x2000,
    op_div      = 0x3000,
    op_mod      = 0x4000,
    op_bitand   = 0x5000
};