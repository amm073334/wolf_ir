#pragma once

#include <string>
#include <vector>
#include <array>
#include <utility>

enum exec_type : char {
    when_called,
    on_condition,
    on_parallel_condition,
    always
};

enum exec_comp_type : char {
    greater_than,
    greater_or_equal,
    equal,
    less_or_equal,
    less_than,
    not_equal,
    bitwise_and
};

enum arg_flag_type : char {
    none,
    db,
    enum_
};

enum color_type : int32_t {
    black,
    red,
    blue,
    green,
    purple,
    yellow,
    gray
};

/**
 * A line of code is represented with a list of integers and
 * a list of strings, along with an indent level. There is
 * always at least one integer, which is the command ID.
 * 
 * If the indent level is malformed, the common will not load.
*/
struct Line {
    std::vector<int32_t> int_fields;
    std::vector<std::string> str_fields;
    char indent_level = 0;
};

typedef std::vector<std::pair<std::string, int32_t>> EnumList;

class CommonEvent {    
public:
    CommonEvent();

    /**
     * Emits the entire common event object to output.
    */
    void emit_common(std::ofstream *fs);

    /**
     * Length of the string array containing arg names.
    */
    static const int32_t MAX_NUM_ARG_NAMES = 11;

    /**
     * Length of the byte array containing arg type flags.
    */
    static const int32_t MAX_NUM_ARG_FLAGS = 10;

    /**
     * Length of the array of enums; one for each of the ten args.
    */
    static const int32_t MAX_NUM_ENUM_LISTS = 10;

    /**
     * Length of the array of integers containing default integer arg values.
    */
    static const int32_t MAX_NUM_DEFAULTABLE_ARGS = 5;
    
    /**
     * Length of the array of strings containing cself names.
     */    
    static const int32_t MAX_NUM_CSELF_NAMES = 100;
    
    
    int32_t id = 0;
    std::string name = "";
    color_type color = black;
    std::string memo = "";
    
    exec_type exec = when_called;
    exec_comp_type exec_op = greater_than;
    int32_t cond_yobidasi = 2000000;
    int32_t cond_comp_value = 0;

    char num_int_args = 0;
    char num_str_args = 0;

    std::array<std::string, MAX_NUM_ARG_NAMES> arg_names;
    std::array<arg_flag_type, MAX_NUM_ARG_FLAGS> arg_flags;
    std::array<EnumList, MAX_NUM_ENUM_LISTS> enums;
    std::array<int32_t, MAX_NUM_DEFAULTABLE_ARGS> default_args;
    std::array<std::string, MAX_NUM_CSELF_NAMES> cself_names;
    
    std::vector<Line> lines;

    std::string return_name = "";
    int32_t return_cself_id = 0;

private:

    std::ofstream* fs;

    /**
     * Writes to output, interpreting the input
     * value as bytes.
     * @param in The value to emit.
    */
    void emit(int32_t in);
    void emit(char in);
    void emit(std::string in);

    /**
     * Emits the header of the common event to output.
    */
    void emit_header();

    /**
     * Emits a code line to output, formatted as:
     * An 8-bit number of integer fields,
     * the array of 32-bit integer fields,
     * the 8-bit indent level of the line,
     * an 8-bit number of string fields,
     * the array of string fields,
     * and one byte of padding.
     * @param l The line to emit.
    */
    void emit_line(Line l);

    /**
     * Emits the footer of the common event to output.
    */
    void emit_footer();



};
