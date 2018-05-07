#ifndef CYBER_WORM
#define CYBER_WORM
#include <iostream>
#include <string>
#include <vector>


class CyberWorm
{
private:
    const std::string 	cyber_worm_os_;
    const std::string 	cyber_worm_name_;
    const int 	cyber_worm_dormancy_time_;
    CyberWorm(); // Prevent the use of an empty constructor

public:
    CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time); //constructor
    CyberWorm(const CyberWorm& other); //copy constructor;
    const std::string get_cyber_worm_os(); //worm os getter
    const std::string get_cyber_worm_name(); //worm name getter
    const int get_cyber_worm_dormancy_time(); //dormancy time getter

};


#endif
