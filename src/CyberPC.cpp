#include <iostream>
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberWorm.h"
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberPC.h"


	 CyberPC::CyberPC(): //empty constructor
        cyber_pc_os_(NULL),
        cyber_pc_name_(NULL),
        cyber_pc_time_to_infect_(-1),
		cyber_pc_connections_(0)
    {}

    CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name): //constructor
        cyber_pc_os_(cyber_pc_os),
        cyber_pc_name_(cyber_pc_name),
        cyber_pc_time_to_infect_(-1),
		cyber_pc_connections_(0)
    {}


    CyberPC::~CyberPC(){ //cyber pc destructor
	   delete cyber_worm_;
   }

    const std::string CyberPC::getName(){ //name getter
       return cyber_pc_name_;
    }


    void CyberPC::AddConnection(std::string  second_pc){    // Add a connection to this PC
        cyber_pc_connections_.push_back(second_pc);
        std::cout<<"\t"<<cyber_pc_name_<<" now connected to "<< second_pc<<"\n";
    }

	void CyberPC::Infect(CyberWorm & worm){   // Add a worm to this PC
        if (worm.get_cyber_worm_os()==cyber_pc_os_){
        	if(cyber_worm_!=NULL){
        		delete cyber_worm_;
        	}
				cyber_worm_ = new CyberWorm(worm);
				cyber_pc_time_to_infect_ = worm.get_cyber_worm_dormancy_time();
		        std::cout<<"\t\t"<<cyber_pc_name_<<" now infected by "<< worm.get_cyber_worm_name()<<"\n";
        }
        else{
        	std::cout<<"\t\t"<<"Worm "<<worm.get_cyber_worm_name()<<" incompatible with "<<cyber_pc_name_<<"\n";
        }
	}

	void CyberPC::Run(const CyberDNS & server){			// Activate PC and infect others if worm is active
		if(cyber_pc_time_to_infect_<=0 && cyber_worm_!=NULL){
			std::cout<<"\t"<<cyber_pc_name_<<" infecting... "<<"\n";
			std::vector<std::string>::iterator it;
			for(it=cyber_pc_connections_.begin(); it!=cyber_pc_connections_.end(); ++it){
				server.GetCyberPC(*it).Infect(*cyber_worm_);
			}
		}
		else{
			if(cyber_worm_!=NULL){
				std::cout<<"\t"<<cyber_pc_name_<<": worm "<<cyber_worm_->get_cyber_worm_name()<<" is dormant "<< "\n";
			}
		}
		cyber_pc_time_to_infect_--;
	}

	void CyberPC::Disinfect(){           // called by cyber expert, disinfect PC
		if (cyber_worm_!=NULL){
			std::cout<<"\t\t"<<"worm "<<cyber_worm_->get_cyber_worm_name()<<" successfully removed from "<<cyber_pc_name_<< "\n";
			delete cyber_worm_;
			cyber_worm_=NULL;
			cyber_pc_time_to_infect_=1;
		}
	}


