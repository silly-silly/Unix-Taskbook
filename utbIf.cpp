#include "tasklib.hpp"
#include "pt4utilities.hpp"

class utbIf : public TaskLib
{
private:
	std::string task_group;
	std::string libname;

public:
	utbIf();
	virtual ~utbIf() {}

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
    return new utbIf;
}

extern "C" void destroy(TaskLib *t)
{
    delete t;
}


utbIf::utbIf()
{
#if defined __linux__
    library_name = "libutbIf.so";
#elif defined __APPLE__
    library_name = "libutbIf.dylib";
#endif

    compiler = "gcc";
    compile_argv = {compiler, "-Wall", "", "ut1.c", "-o"};

    task_group = "If";
    task_count = 30;
    total_test_count = 2;
	libname="libpt4";

    print_file = false;
    print_task_info = true; 
}
