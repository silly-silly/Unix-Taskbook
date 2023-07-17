#include "tasklib.hpp"
#include "pt4utilities.hpp"

class utbZSeries : public TaskLib
{
private:
	std::string task_group;
	std::string libname;

public:
	utbZSeries();
	virtual ~utbZSeries() {}

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
    return new utbZSeries;
}

extern "C" void destroy(TaskLib *t)
{
    delete t;
}


utbZSeries::utbZSeries()
{
#if defined __linux__
    library_name = "libutbZSeries.so";
#elif defined __APPLE__
    library_name = "libutbZSeries.dylib";
#endif

    compiler = "gcc";
    compile_argv = {compiler, "-Wall", "", "ut1.c", "-o"};

    task_group = "ZSeries";
    task_count = 40;
    total_test_count = 3;
	libname="libpt4a";

    print_file = false;
    print_task_info = true; 
}