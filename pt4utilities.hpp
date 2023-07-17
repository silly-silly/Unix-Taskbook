#ifndef PT4UTILITIES_HPP
#define PT4UTILITIES_HPP
#include <string>

void pt4_print_task_info(std::string libname, std::string task_group, int task_num, int language_option);
void pt4_generate_task_test(std::string task_group, int task_num, int test_num);
void pt4_print_extra_info(std::string task_group, int task_num);
int pt4_check_program(std::string task_group, int test_num);

#endif