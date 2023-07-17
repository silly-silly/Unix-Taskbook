#include "tasklib.hpp"
#include "pt4utilities.hpp"

class utbZArray : public TaskLib
{
private:
	std::string task_group;
	std::string libname;

public:
	utbZArray();
	virtual ~utbZArray() {}

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
    return new utbZArray;
}

extern "C" void destroy(TaskLib *t)
{
    delete t;
}


utbZArray::utbZArray()
{
#if defined __linux__
    library_name = "libutbZArray.so";
#elif defined __APPLE__
    library_name = "libutbZArray.dylib";
#endif

    compiler = "gcc";
    compile_argv = {compiler, "-Wall", "", "ut1.c", "-o"};

    task_group = "ZArray";
    task_count = 140;
    total_test_count = 3;
	libname="libpt4b";

    print_file = false;
    print_task_info = true; 
}