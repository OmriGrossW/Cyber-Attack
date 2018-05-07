#include <iostream>
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberExpert.h"

	CyberExpert::CyberExpert(): //empty constructor
        cyber_expert_name_(NULL),
        cyber_expert_work_time_(-1),
        cyber_expert_rest_time_(-1),
        cyber_expert_efficiency_(-1),
		workTimeLeft(-1),
		restTimeLeft(-1)
    {}


	CyberExpert::CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_): //constructor
        cyber_expert_name_(cyber_expert_name_),
        cyber_expert_work_time_(cyber_expert_work_time_),
        cyber_expert_rest_time_(cyber_expert_rest_time_),
        cyber_expert_efficiency_(cyber_expert_efficiency_),
		workTimeLeft(cyber_expert_work_time_),
		restTimeLeft(cyber_expert_rest_time_)
    {}

    void CyberExpert::Clean(CyberPC & cyber_pc){ //sends cyber expert to clean (disinfect) a pc
    	cyber_pc.Disinfect();

 	}

    const std::string CyberExpert::get_cyber_expert_name(){ //name getter
    	return cyber_expert_name_;
    }
    const int CyberExpert::get_cyber_expert_efficiency(){ //efficiency getter
     	return cyber_expert_efficiency_;
     }

    int CyberExpert::getWorkTimeLeft(){ //work time left getter
        return workTimeLeft;
    }


    void CyberExpert::dayPassed(){ 	//calculates the work time and the rest time for each experts every day passing by
    	if (workTimeLeft>0){
    		workTimeLeft--;
    		if (workTimeLeft==0){
		      if(restTimeLeft==0){
			    workTimeLeft=cyber_expert_work_time_;
		      }
		      else{
			    std::cout<<"\t"<<cyber_expert_name_<<" is taking a break"<<"\n";
		      }
    		}

    	}
    	else if (restTimeLeft>0){
			restTimeLeft--;
			if(restTimeLeft==0){
				std::cout<<"\t"<<cyber_expert_name_<<" is back to work"<<"\n";
				workTimeLeft=cyber_expert_work_time_;
				restTimeLeft=cyber_expert_rest_time_;
			}
    	}
    }


