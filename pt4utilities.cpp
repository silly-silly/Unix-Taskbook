#include <string>
#include <iostream>
#include <iomanip>
#include <dlfcn.h>
#include <unistd.h>
#include "uprint.cpp"
#include "udata.cpp"

using namespace std;

typedef void  (*create_group)(const char*);
typedef void  (*create_test) (int,int);

typedef void  __attribute__ (( stdcall )) (*create_group)(const char*);
typedef void  __attribute__ (( stdcall )) (*create_test) (int,int);
bool LoadLib(string name,string group,int test,int task)
{
    char* error;
    bool result = false;
    void *handle;
    handle = dlopen(name.c_str(),RTLD_LAZY);
    if(!handle){
        cerr <<"cannot load libary:"<<dlerror()<<"\n";
        return result;
    }
    dlerror();
    create_group create_g;
    create_g= (create_group)dlsym(handle, "initgroup");
    if((error = dlerror())!= NULL){
        cerr <<"cannot load group:"<<dlerror()<<"\n";
        return result;
    }
    create_g(group.c_str());
    create_test create_t;
    create_t = (create_test)dlsym(handle, "inittask");
    if((error=dlerror())!=NULL){
        cerr <<"cannot load task:"<<dlerror()<<"\n";
        return result;
    }
    create_t(test,task);
    dlclose(handle);
    result = true;
    return result;
}
string Libname(string libname,int language_option)
{
    string name;
    if(language_option == 1) name = libname+"_ru";
    if(language_option == 0) name = libname+"_en";
    #if defined __linux__
    name = name+".so";
    #elif defined __APPLE__
    name = name+".dylib"
    #endif
    return name;
}

void pt4_print_task_info(std::string libname, std::string task_group, int task_num, int language_option)
{
// shows task info (see InitPrg)
//	std::cout << "<<<Task formulation output>>>" << std::endl;
    std::string name=Libname(libname,language_option);
	LoadLib(name,task_group,task_num, 0);
	if(LoadData()) {
            PrintTaskDemo();
    }
}

void pt4_generate_task_test(std::string task_group, int task_num, int test_num)
{
// creates all necessary files for selected task (see InitPrg)
//	std::cout << "<<<Creation of required files>>>" << std::endl;
	//LoadLib(task_group,task_num, test_num);
	if(LoadData()) {
            CreateAddFiles();
    }
}

void pt4_print_extra_info(std::string task_group, int task_num)
{
// shows results (see CheckPrg)
//	std::cout << "<<<Task results output>>>" << std::endl;
    if (LoadData())
    {
        PrintTask();
    }
}

int pt4_check_program(std::string task_group, int test_num)
{
/*
	std::cout << "<<<Checking the results>>>" << std::endl;
    if (LoadData())
    {
        CheckResults(0);
    }
	return 0;
	*/
	    bool result = false;
	//std::cout<< "<<<Checking the results>>>" << std::endl;
    if (LoadData())
    {
        result = CheckAllResults();
    }
	return result ? 0 : 1;

// checks results (see CheckPrg)
}
