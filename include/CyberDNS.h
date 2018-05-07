#ifndef CYBERDNS
#define CYBERDNS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include </usr/local/boost/1.57.0/include/boost/property_tree/ptree.hpp>
#include </usr/local/boost/1.57.0/include/boost/property_tree/xml_parser.hpp>
#include </usr/local/boost/1.57.0/include/boost/foreach.hpp>
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberPC.h"

using namespace boost;
using namespace boost::property_tree;

class CyberPC; //Forward deceleration

class CyberDNS
{
private:
    std::map<const std::string, CyberPC &> cyber_DNS_;	//Hash map to hold PC names and pointers
    std::vector<std::string> cyber_PC_list_; //vector that stores the PCs on the network
public:
    CyberDNS();//constructor
    ~CyberDNS();//CyberDNS Destructor
    void AddPC(CyberPC & cyber_pc_); //adds pc to network
    CyberPC & GetCyberPC(const std::string & cyber_pc_name) const; //returns the address of cyber pc by name
    std::vector<std::string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.
							// All access to PC objects should use this function
							// Do not store pointers elsewhere!
};

#endif
