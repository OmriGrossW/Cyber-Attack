#include <iostream>
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberWorm.h"

	CyberWorm::CyberWorm(): //empty constructor
        cyber_worm_os_(NULL),
        cyber_worm_name_(NULL),
        cyber_worm_dormancy_time_(-1)
   {}

   CyberWorm::CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time): //constructor
        cyber_worm_os_(cyber_worm_os),
        cyber_worm_name_(cyber_worm_name),
        cyber_worm_dormancy_time_(cyber_worm_dormancy_time)
   {}

   CyberWorm::CyberWorm(const CyberWorm& other): //copy constructor;
        cyber_worm_os_ (other.cyber_worm_os_),
        cyber_worm_name_ (other.cyber_worm_name_),
        cyber_worm_dormancy_time_ (other.cyber_worm_dormancy_time_)
    {}

   const int CyberWorm::get_cyber_worm_dormancy_time(){ //dormancy time getter
	   return cyber_worm_dormancy_time_;
   }

   const std::string CyberWorm::get_cyber_worm_os(){ //worm os getter
	   return cyber_worm_os_;
   }

   const std::string CyberWorm::get_cyber_worm_name(){ //worm name getter
	   return cyber_worm_name_;
   }
