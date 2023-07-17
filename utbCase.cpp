#include "tasklib.hpp"
#include "pt4utilities.hpp"

class utbCase : public TaskLib
{
private:
	std::string task_group;
	std::string libname;

public:
	utbCase();
	virtual ~utbCase() {}

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
    return new utbCase;
}

extern "C" void destroy(TaskLib *t)
{
    delete t;
}


utbCase::utbCase()
{
#if defined __linux__
    library_name = "libutbCase.so";
#elif defined __APPLE__
    library_name = "libutbCase.dylib";
#endif

    compiler = "gcc";
    compile_argv = {compiler, "-Wall", "", "ut1.c", "-o"};

    task_group = "Case";
    task_count = 20;
    total_test_count = 2;
	libname="libpt4";

    print_file = false;
    print_task_info = true; 
}
