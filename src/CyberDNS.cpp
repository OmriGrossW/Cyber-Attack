
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberDNS.h"


	CyberDNS::CyberDNS()//constructor
	{}

	 CyberDNS::~CyberDNS(){  //CyberDNS Destructor 
	    	std::map<const std::string, CyberPC &>::iterator it;
	    	for (it=cyber_DNS_.begin(); it!=cyber_DNS_.end(); ++it){ //deleting each pc on the specific network
	    		delete &(it)->second;
	    	}
	    	cyber_DNS_.clear();
	    }
 
	void CyberDNS::AddPC(CyberPC & cyber_pc_){ //adds pc to network
		cyber_DNS_.insert(std::pair<const std::string, CyberPC &>(cyber_pc_.getName(),cyber_pc_));
	}

	CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name)const{ //returns the address of cyber pc by name
        return cyber_DNS_.find(cyber_pc_name)->second;
	}

    std::vector<std::string> CyberDNS::GetCyberPCList(){  // Return list of PC's as a vector of strings.
    	std::vector<std::string> cyber_PC_list_;
    	std::map<const std::string, CyberPC &>::reverse_iterator it;
		for (it=cyber_DNS_.rbegin(); it!=cyber_DNS_.rend(); ++it){
			cyber_PC_list_.push_back(it->second.getName());
		}
		return cyber_PC_list_;
    }
