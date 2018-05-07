#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberPC.h"


class CyberExpert
{
private:
    const std::string cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    int workTimeLeft;
    int restTimeLeft;
    CyberExpert(); // Prevent the use of an empty constructor

public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_); //constructor
    void Clean(CyberPC & cyber_pc); //sends cyber expert to clean (disinfect) a pc
    const std::string get_cyber_expert_name();//name getter
    const int get_cyber_expert_efficiency();//efficiency getter
    int getWorkTimeLeft(); //work time left getter
    void dayPassed(); //calculates the work time and the rest time for each experts every day passing by
};


#endif
