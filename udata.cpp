#include "udata.h"
#include "uprint.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <vector>
#include <map>
#include "box_drawings.hpp"
#include <algorithm>

// Declare variables
int TaskCount, NumberOfTests, NumberOfUsedData,
    TaskNumber, TestNumber;
int DataHeight, ResultHeight;
std::string GrTopic, GrDescr, GrAuthor;
TDataArray idata, odata;
TCommentArray icmt, ocmt, ttext;
int nttext, nicmt, nocmt, nidata, nodata, cursize;

// 2023.02>
TDataArray rdata;
int nrdata;
std::vector<std::string> headerinfos;
std::vector<std::vector<TData>> odata_procs;

// 2023.03>
bool check_result = false;

bool LoadData()
{
    std::ifstream f(FileName.c_str());
    if (!f.good())
    {
        return false;
    }
    try
    {
        std::string ver;
        getline(f, ver);
        if (ver != "V1.1")
        {
            return false;
        }
        getline(f, GrTopic);
        getline(f, GrDescr);
        getline(f, GrAuthor);
        f >> TaskCount >> TaskNumber >> NumberOfTests >> TestNumber >> NumberOfUsedData >> DataHeight >> ResultHeight;
        f >> nttext >> nicmt >> nocmt >> nidata >> nodata >> cursize;
        f.ignore(); // Ignore end of line after integers
        for (int i = 0; i < nttext; ++i)
        {
            f >> ttext[i].x >> ttext[i].y;
            f.ignore();
            getline(f, ttext[i].s);
        }
        for (int i = 0; i < nicmt; ++i)
        {
            f >> icmt[i].x >> icmt[i].y;
            f.ignore();
            getline(f, icmt[i].s);
        }
        for (int i = 0; i < nocmt; ++i)
        {
            f >> ocmt[i].x >> ocmt[i].y;
            f.ignore();
            getline(f, ocmt[i].s);
        }
        for (int i = 0; i < nidata; ++i)
        {
            f >> idata[i].id >> idata[i].x >> idata[i].y >> idata[i].w >> idata[i].p >> idata[i].r;
            f.ignore();
            switch (idata[i].id)
            {
            case 'b':
            case 'i':
            case 'r':
                f >> idata[i].n;
                break;
            case 'c':
            case 's':
                getline(f, idata[i].s);
                break;
            }
        }
        for (int i = 0; i < nodata; ++i)
        {
            f >> odata[i].id >> odata[i].x >> odata[i].y >> odata[i].w >> odata[i].p >> odata[i].r;
            f.ignore();
            switch (odata[i].id)
            {
            case 'b':
            case 'i':
            case 'r':
                f >> odata[i].n;
                break;
            case 'c':
            case 's':
                getline(f, odata[i].s);
                break;
            }
        }
        f.close();
        return true;
    }
    catch (...)
    {
        return false;
    }
}

void CreateAddFiles()
{
    std::ofstream f("ut1inf.dat");
    f << "11" << std::endl;             // Taskbook version
    f << cursize << std::endl;          // number of processes
    f << NumberOfUsedData << std::endl; // number of used data (in the process 0);
    f.close();

    for (int i = 0; i <= 100; i++)
    {
        if (std::filesystem::exists("ut1in" + std::to_string(i) + ".dat"))
        {
            std::filesystem::remove("ut1in" + std::to_string(i) + ".dat");
        }
        if (std::filesystem::exists("ut1out" + std::to_string(i) + ".dat"))
        {
            std::filesystem::remove("ut1out" + std::to_string(i) + ".dat");
        }
        if (std::filesystem::exists("ut1err" + std::to_string(i) + ".dat"))
        {
            std::filesystem::remove("ut1err" + std::to_string(i) + ".dat");
        }
        if (std::filesystem::exists("ut1sh" + std::to_string(i) + ".dat"))
        {
            std::filesystem::remove("ut1sh" + std::to_string(i) + ".dat");
        }
    }

    std::ofstream file;
    bool isOpen;
    for (int i = 0; i < cursize; i++)
    {
        isOpen = false;
        for (int j = 0; j < nidata; j++)
        {
            if (idata[j].r == i)
            {
                if (!isOpen)
                {
                    file.open("ut1in" + std::to_string(i) + ".dat");
                    isOpen = true;
                }
                file << idata[j].id << std::endl;
                switch (idata[j].id)
                {
                case 'b':
                case 'i':
                    file << std::round(idata[j].n) << std::endl; // TODO: this 'round' is dirfferent from the one in pascal
                    break;
                case 'r':
                    file << idata[j].n << std::endl;
                    break;
                case 'c':
                case 's':
                    file << idata[j].s << std::endl;
                    break;
                }
            }
        }
        if (isOpen)
        {
            file.close();
        }
    }
}

bool CompareResult(int i, const std::vector<TData> &odata_, const std::vector<TData> &rdata_)
{
    std::string s1, s2;
    std::stringstream ss1, ss2;
    switch (odata_[i].id)
    {
    case 'b':
    case 'i':
        return std::round(rdata_[i].n) == std::round(odata_[i].n);
    case 'r':
        ss1 << std::fixed << std::setprecision(rdata_[i].p) << rdata_[i].n;
        ss2 << std::fixed << std::setprecision(odata_[i].p) << odata_[i].n;
        s1 = ss1.str();
        s2 = ss2.str();
        return s1 == s2;
    case 'c':
    case 's':
        return rdata_[i].s == odata_[i].s;
    default:
        return false;
    }
}

bool CheckResults(int rank)
{
    std::ifstream f;
    double n;
    char id;
    std::string s;
    int i;

    std::vector<TData> odata_ = odata_procs[rank];
    std::vector<TData> rdata_;
    rdata_.resize(201);
    int nodata_ = odata_.size();
    int nrdata_ = 0;
    // headerinfo = "";
    std::string err_file = "ut1err" + std::to_string(rank) + ".dat";
    if (std::filesystem::exists(err_file))
    {
        f.open(err_file);
        std::getline(f, headerinfos[rank]);
        f.close();
    }

    std::string out_file = "ut1out" + std::to_string(rank) + ".dat";
    if (std::filesystem::exists(out_file))
    {
        f.open(out_file);
        while (!f.eof())
        {
            f >> id;
            f.ignore();
            // add this if block to gurantee not to read blank row
            if (f.eof())
                break;
            if (nrdata_ == nodata_)
            {
                if (headerinfos[rank] == "")
                {
                    headerinfos[rank] = TooManyOutputMsg;
                }
                break;
            }

            if (id != odata_[nrdata_].id)
            {
                if (headerinfos[rank] == "")
                {
                    headerinfos[rank] = WrongTypeOutputMsg;
                }
                break;
            }

            rdata_[nrdata_] = odata_[nrdata_];

            switch (id)
            {
            case 'b':
            case 'i':
            case 'r':
                f >> rdata_[nrdata_].n;
                f.ignore();
                break;
            case 'c':
            case 's':
                std::getline(f, rdata_[nrdata_].s);
                break;
            }
            rdata[nrdata] = rdata_[nrdata_];
            nrdata++;
            nrdata_++;
        }
        f.close();
    }
    else if (nodata_ == 0 && headerinfos[rank] == "")
    {
        headerinfos[rank] = RightSolutionMsg;
        return true;
    }
    else if (headerinfos[rank] != "")
    {
        return false;
    }

    if (nrdata_ == 0)
    {
        if (headerinfos[rank] == NoInputMsg)
        {
            headerinfos[rank] = AcquaintanceRunMsg;
        }
        if (headerinfos[rank] == "")
        {
            headerinfos[rank] = NoOutputMsg;
        }
        return false;
    }

    if (headerinfos[rank] != "")
    {
        return false;
    }

    if (nrdata_ < nodata_)
    {
        headerinfos[rank] = NotAllOutputMsg;
        return false;
    }

    for (i = 0; i < nodata_; i++)
    {
        if (!CompareResult(i, odata_, rdata_))
        {
            headerinfos[rank] = WrongSolutionMsg;
            return false;
        }
    }

    headerinfos[rank] = RightSolutionMsg;
    return true;
}

bool CheckAllResults()
{
    nrdata = 0;
    check_result = true;
    headerinfos.assign(cursize, "");
    odata_procs.resize(cursize);
    for (int i = 0; i < cursize; ++i)
    {
        std::vector<TData> odata_i;
        for (int j = 0; j < nodata; ++j)
        {
            if (odata[j].r == i)
            {
                odata_i.emplace_back(odata[j]);
            }
        }
        odata_procs[i] = odata_i;
        if (i == 0) continue;
        check_result = CheckResults(i) && check_result;
    }

    if (check_result) check_result = CheckResults(0);
    else 
    {
        CheckResults(0);
        headerinfos[0] = WrongSolutionMsg;
    }

    return check_result;
}

std::string InitString(char c) {
    return std::string(MaxWidth, c);
}

std::string check_bg(const std::string &RunInfo)
{
    std::string bg_color = "";
    if (RunInfo == NotAllOutputMsg || RunInfo == NotAllInputMsg || RunInfo == NoOutputMsg || RunInfo == NoInputMsg)
        bg_color = colors::BG_YELLOW;
    else if (RunInfo == TooManyOutputMsg || RunInfo == TooManyInputMsg)
        bg_color = colors::BG_BRIGHT_RED;
    else if (RunInfo == WrongTypeOutputMsg || RunInfo == WrongTypeInputMsg)
        bg_color = colors::BG_BRIGHT_MAGENTA;
    else if (RunInfo == WrongSolutionMsg)
        bg_color = colors::BG_RED;
    else if (RunInfo == RightSolutionMsg)
        bg_color = colors::BG_GREEN;
    else if (RunInfo == DemoRunMsg)
        bg_color = colors::BG_BLUE;
    return bg_color;
}

// print header info
void PrintHeader(const std::vector<std::string> &RunInfos)
{

    std::map<std::string, std::vector<int>> groups;
    for (int i = 0; i < cursize; i++)
    {
        groups[RunInfos[i]].push_back(i);
    }

    std::vector<std::string> s(2);
    std::string s1 = InitString(' ');
    std::string s2 = InitString('-');
    // s[0] = s2;
    // PrintCmt(s[0], ' ' + GrTopic << std::to_string(TaskNumber) + " [" + GrDescr + "] ", 4);
    // PrintCmt(s[0], '(' << std::to_string(TestNumber) + ')', 75);
    // std::cout << '-' << s[0] << '-' << std::endl;
    int cnt = 0;
    for (; cnt < 4; cnt++)
    {
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
    }
    s[0] = s[0] + " " + GrTopic + std::to_string(TaskNumber) + " [" + GrDescr + "] ";
    for (int i = s[0].length() - cnt * 2; i < 75; i++)
    {
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
        cnt++;
    }
    s[0] = s[0] + '(' + std::to_string(TestNumber) + ')';
    for (int i = s[0].length() - cnt * 2; i < MaxWidth; i++)
    {
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
        cnt++;
    }
    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_DOWN_AND_RIGHT << s[0] << box_drawings::LIGHT_DOWN_AND_LEFT << colors::WHITE << colors::BOLD  << std::endl;
    for (const auto &group : groups)
    {
        if (group.first == RightSolutionMsg)
            continue;
        std::ostringstream oss1;
        std::ostringstream oss2;
        for (const auto &index : group.second)
        {
            oss1 << index << ",";
        }
        std::string tmp = oss1.str();
        std::string procs = tmp.substr(0, tmp.length() - 1);
        //oss2 << std::setw(8) << procs << " | " << group.first;
        oss2 << group.first;
        s[1] = s1;
        // PrintCmt(s[1], oss2.str(), 2);
        // std::cout << '|' << s[1] << '|' << std::endl;
        PrintCmt(s[1], oss2.str(), 2);
        std::string bg_color = check_bg(group.first);
        std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL << bg_color << s[1] << colors::RESET << box_drawings::LIGHT_VERTICAL << colors::WHITE << colors::BOLD  << std::endl;
    }
}


// print header info
void PrintHeader(const std::string RunInfo)
{
    std::vector<std::string> s(2);
    std::string s1 = InitString(' ');
    std::string s2 = InitString('-');
    // s[0] = s2;
    // PrintCmt(s[0], ' ' + GrTopic << std::to_string(TaskNumber) + " [" + GrDescr + "] ", 4);
    // PrintCmt(s[0], '(' << std::to_string(TestNumber) + ')', 75);
    // std::cout << '-' << s[0] << '-' << std::endl;
    // s[1] = s1;
    // PrintCmt(s[1], RunInfo, 2);
    // std::cout << '|' << s[1] << '|' << std::endl;
    int cnt = 0;
    for (; cnt < 4; cnt++)
    {
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
    }
    s[0] = s[0] + " " + GrTopic + std::to_string(TaskNumber) + " [" + GrDescr + "] ";
    for (int i = s[0].length() - cnt * 2; i < 75; i++)
    {
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
        cnt++;
    }
    s[0] = s[0] + '(' + std::to_string(TestNumber) + ')';
    for (int i = s[0].length() - cnt * 2; i < MaxWidth; i++)
    {
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
        cnt++;
    }
    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_DOWN_AND_RIGHT << s[0] << box_drawings::LIGHT_DOWN_AND_LEFT << colors::WHITE << colors::BOLD  << std::endl;
    s[1] = s1;
    PrintCmt(s[1], RunInfo, 2);
    std::string bg_color = check_bg(RunInfo);
    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL << bg_color << s[1] << colors::RESET << box_drawings::LIGHT_VERTICAL << colors::WHITE << colors::BOLD  << std::endl;
}

// print task text
void PrintTaskText()
{
    std::vector<std::string> s(nttext + 1);
    std::string s1 = InitString(' ');
    std::string s2 = InitString('-');
    // s[0] = s2;
    // for (int i = 1; i <= nttext; ++i)
    // {
    //     s[i] = s1;
    // }
    // for (int i = 0; i < nttext; ++i)
    // {
    //     PrintCmt(s[ttext[i].y], ttext[i].s, ttext[i].x);
    // }
    // std::cout << '-' << s[0] << '-' << std::endl;
    // for (int i = 1; i <= nttext; ++i)
    // {
    //     std::cout << '|' << s[i] << '|' << std::endl;
    // }
    for (int i = 0; i < MaxWidth; i++)
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
    for (int i = 1; i <= nttext; i++)
        s[i] = s1;
    for (int i = 0; i <= nttext - 1; i++)
        PrintCmt(s[ttext[i].y], ttext[i].s, ttext[i].x);
    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL_AND_RIGHT << s[0] << box_drawings::LIGHT_VERTICAL_AND_LEFT << colors::WHITE << colors::BOLD  << std::endl;
    for (int i = 1; i <= nttext; i++)
        std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL << s[i] << box_drawings::LIGHT_VERTICAL << colors::WHITE << colors::BOLD  << std::endl;
}

void PrintData(TDataArray a, int na, TCommentArray b, int nb, int size, std::string title, bool check)
{
    std::vector<std::string> s(size + 1);
    std::string s1 = InitString(' ');
    std::string s2 = InitString('-');
    // s[0] = s2;
    // for (int i = 1; i <= size; i++)
    // {
    //     s[i] = s1;
    // }
    for (int i = 1; i <= size; i++)
        s[i] = s1;
    // s[0]=PrintCmt(s[0], " " + title +" ", 4);
    int cnt = 1;
    for (; cnt < 4; cnt++)
    {
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
    }
    s[0] = s[0] + " " + title + " ";
    for (int i = s[0].length() - cnt * 2; i < MaxWidth - 2; i++)
        s[0] = s[0] + box_drawings::LIGHT_HORIZONTAL;
    //PrintCmt(s[0], " " + title + " ", 4);
    for (int i = 0; i < na; i++)
    {
        switch (a[i].id)
        {
        case 'b':
            PrintB(s[a[i].y], std::round(a[i].n), a[i].x);
            break;
        case 'i':
            PrintN(s[a[i].y], std::round(a[i].n), a[i].x, a[i].w, check);
            break;
        case 'r':
            PrintR(s[a[i].y], a[i].n, a[i].x, a[i].w, a[i].p, check);
            break;
        case 'c':
            PrintC(s[a[i].y], a[i].s[0], a[i].x);
            break;
        case 's':
            PrintS(s[a[i].y], a[i].s, a[i].x, a[i].w);
            break;
        }
    }
    for (int i = 0; i < nb; i++)
    {
        PrintCmt(s[b[i].y], b[i].s, b[i].x);
    }
    // std::cout << "-" << s[0] << "-" << std::endl;
    // for (int i = 1; i <= size; i++)
    // {
    //     std::cout << "|" << s[i] << "|" << std::endl;
    // }
    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL_AND_RIGHT << s[0] << box_drawings::LIGHT_VERTICAL_AND_LEFT << colors::WHITE << colors::BOLD  << std::endl;
    // print color
    for (int i = 1; i <= size; i++)
    {
        int color = 0;
        std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL << colors::RESET;
        std::string s0=s[i];
        s0.erase(std::remove(s0.begin(), s0.end(), ' '), s0.end());
        if(s0.back()=='*'){
            for (int j = 0; j < s[i].length(); j++)
            {
                if (color == 0){
                    std::cout << colors::BLACK << colors::BOLD << s[i][j] << colors::RESET;
                if (j + 1 < s[i].length())
                {
                    if (s[i][j] == '\"') color =1;
                }
                }
                else {
                    if(s[i][j]=='*'&&s[i][j+1]==' ') {
                        std::cout<<colors::RED<<s[i][j]<<colors::RESET;
                        color=0;
                    }
                    else
                    std::cout << colors::BRIGHT_YELLOW << s[i][j] << colors::RESET;
                }
            }
        } 
        else
        {
           for (int j = 0; j < s[i].length(); j++)
            {
            if (color == 0)
            {
                std::cout << colors::BLACK << colors::BOLD << s[i][j] << colors::RESET;
                if (j + 1 < s[i].length())
                {
                    if (s[i][j] == '\"')
                    {
                        if(j>1)
                        {
                            if(s[i][j-1]==' ') color = 1;
                            else color=0;
                        }
                    else color=1;
                    }
                    if (s[i][j] == '\'')
                    {
                        if(j>1){
                        if(s[i][j-1]==' ') color = 1;
                        else color=0;
                        }
                    else color=1;
                    }
                    if(s[i][j]==' '||s[i][j]=='='){
                        if ((s[i][j + 1] >= '0') && (s[i][j + 1] <= '9')){
                            color = 1;
                        }
                        if(s[i][j+1]=='-'){
                             if ((s[i][j + 2] >= '0') && (s[i][j + 2] <= '9')){
                            color = 1;
                        }
                        }
                        
                    }
                }
            }
            else
            {
                std::cout << colors::BRIGHT_YELLOW << s[i][j] << colors::RESET;
                if ((s[i][j] >= '0') && (s[i][j] <= '9'))
                {
                    if (s[i][j + 1] == ' ')
                        color = 0;
                }
                if (s[i][j + 1] == '\'')
                    color = 0;
                if (s[i][j + 1] == '\"')
                    color = 0;
            }
            }
        }
        std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL << colors::RESET << std::endl;
    }
}

void PrintEndLine()
{
    // std::cout << "-" << InitString('-') << "-" << std::endl;
    std::string s1 = "";
    for (int i = 0; i < MaxWidth; i++)
    {
        s1 = s1 + box_drawings::LIGHT_HORIZONTAL;
    }
    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_UP_AND_RIGHT << s1 + box_drawings::LIGHT_UP_AND_LEFT << colors::WHITE << colors::BOLD  << std::endl;
}

//check if it is necessary to print show info
bool check_show()
{
    for (int i = 0; i < cursize; ++i)
    {
        std::string show_file = "ut1sh" + std::to_string(i) + ".dat";
        if (std::filesystem::exists(show_file))
        {
            return true;
        }
    }
    return false;
}

void PrintShow()
{
    if (!check_show())
        return;
    std::string s1 = InitString(' ');
    std::string s0 = "";
    // std::string s0 = InitString('-');
    // PrintCmt(s0, " Debug information ", 4);
    // std::cout << "-" << s0 << "-" << std::endl;
    int cnt = 1;
    for (; cnt < 4; cnt++)
    {
        s0 = s0 + box_drawings::LIGHT_HORIZONTAL;
    }
    s0 = s0 + " Debug information ";
    for (int i = s0.length() - cnt * 2; i < MaxWidth - 2; i++)
        s0 = s0 + box_drawings::LIGHT_HORIZONTAL;
    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL_AND_RIGHT << s0 + box_drawings::LIGHT_VERTICAL_AND_LEFT << colors::WHITE << colors::BOLD  << std::endl;
    for (int i = 0; i < cursize; ++i)
    {
        std::string show_file = "ut1sh" + std::to_string(i) + ".dat";
        if (std::filesystem::exists(show_file))
        {

            std::ifstream f(show_file);
            std::string s;
            while (std::getline(f, s))
            {
                while (s.length() > MaxWidth - 2)
                {
                    s0 = s1;
                    PrintCmt(s0, s.substr(0, MaxWidth - 2) + "*", 2);
                    s.erase(0, MaxWidth - 2);
                    // std::cout << "|" << s0 << "|" << std::endl;
                    std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL << s0 + box_drawings::LIGHT_VERTICAL << colors::WHITE << colors::BOLD  << std::endl;
                }
                s0 = s1;
                PrintCmt(s0, s, 2);
                // std::cout << "|" << s0 << "|" << std::endl;
                std::cout << colors::WHITE << colors::BOLD  << box_drawings::LIGHT_VERTICAL << s0 + box_drawings::LIGHT_VERTICAL << colors::WHITE << colors::BOLD  << std::endl;
            }
            f.close();
        }
    }
}

void PrintTaskDemo()
{
    PrintHeader(DemoRunMsg);
    PrintTaskText();
    PrintData(idata, nidata, icmt, nicmt, DataHeight, "Input data", false);
    PrintData(odata, nodata, ocmt, nocmt, ResultHeight, "Example of right solution", false);
    PrintEndLine();
}

void PrintTask()
{
    if (!check_result)
        PrintHeader(headerinfos);
    else
        PrintHeader(RightSolutionMsg);
    PrintTaskText();
    PrintData(idata, nidata, icmt, nicmt, DataHeight, "Input data", false);
    PrintData(rdata, nrdata, ocmt, nocmt, ResultHeight, "Output data", true);
    // if (headerinfo != RightSolutionMsg)
    if (!check_result)
    {
        PrintData(odata, nodata, ocmt, nocmt, ResultHeight, "Example of right solution", false);
    }
    PrintShow();
    PrintEndLine();
}

int GetCursize()
{
    return cursize;
}