#include "tasklib.hpp"
#include "pt4utilities.hpp"

class utbInteger: public TaskLib
{
private:
	std::string task_group;
	std::string libname;

public:
	utbInteger();
	virtual ~utbInteger() {}

    virtual void utb_print_task_info(int task_num, int language_option) 
	{
		pt4_print_task_info(libname,task_group, task_num, language_option);
	}

	virtual void utb_generate_task_test(int task_num, int test_num)
	{
		pt4_generate_task_test(task_group, task_num, test_num);
	}

	virtual void utb_generate_task_control(int task_num) {}

	virtual void utb_print_extra_info(int task_num)
	{
		pt4_print_extra_info(task_group, task_num);
	}

	virtual int utb_check_program(int test_num) const
	{
	 	return pt4_check_program(task_group, test_num);
	}

	// friend class
	friend class UnixTaskbook;

};

extern "C" TaskLib *create()
{
    return new utbInteger;
}

extern "C" void destroy(TaskLib *t)
{
    delete t;
}


utbInteger::utbInteger()
{
#if defined __linux__
    library_name = "libutbInteger.so";
#elif defined __APPLE__
    library_name = "libutbInteger.dylib";
#endif

    compiler = "gcc";
    compile_argv = {compiler, "-Wall", "", "ut1.c", "-o"};

    task_group = "Integer";
    task_count = 30;
    total_test_count = 4;
	libname="libpt4";

    print_file = false;
    print_task_info = true; 
}
