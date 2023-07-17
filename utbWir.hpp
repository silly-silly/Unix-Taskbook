#include "tasklib.hpp"
#include "utilities.hpp"

class utbDir : public TaskLib
{
private:
    std::string sys_cmd;
    std::string work_dir;
    std::string execute_dir;
    std::vector<std::string> extension_name;
    std::vector<std::string> sub_dir;

protected:
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
    void test7();
    void test8();
    void test9();

public:
    utbDir();

    // virtual function inherited from parent class
    virtual void utb_generate_task_test(int task_num, int test_num);
    virtual void utb_generate_task_control(int task_num);
    virtual void utb_print_extra_info(int task_num);
    virtual int utb_check_program(int test_num) const;
    virtual ~utbDir() {}

    // Helper functions are optional
    // In order to implement the above interface, it is assisted by providing
    void generate_test_file(std::string dirname, int count);
};

extern "C" TaskLib *create()
{
    return new utbDir;
}
extern "C" void destroy(TaskLib *t)
{
    delete t;
}