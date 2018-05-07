/*
 * main.cpp

 *
 *  Created on: Nov 20, 2015
 *      Authors: omerbenc & omrigro
 */
#include <iostream>
#include <string>
#include <vector>
#include </usr/local/boost/1.57.0/include/boost/property_tree/ptree.hpp>
#include </usr/local/boost/1.57.0/include/boost/property_tree/xml_parser.hpp>
#include </usr/local/boost/1.57.0/include/boost/foreach.hpp>
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberPC.h"
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberWorm.h"
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberDNS.h"
#include "/users/studs/bsc/2016/omerbenc/workspace/Ass1/include/CyberExpert.h"

void makeComputers(CyberDNS *, const std::string &);
void makeNetwork(CyberDNS *, const std::string &);
void events(CyberDNS *, const std::string &);
void dayRoutine(CyberDNS *);

std::vector<std::string> pcList;
std::vector<CyberExpert*> expertsList;
int currentDay=0;

int main (){
	CyberDNS* dns=new CyberDNS();
	makeComputers(dns,"computers.xml");
	makeNetwork(dns,"network.xml");
	events(dns,"events.xml");


	std::vector<CyberExpert*>::iterator itEx;
    for (itEx=expertsList.begin(); itEx!=expertsList.end(); ++itEx){
		delete (*itEx);
	}
	delete dns;

}

void makeComputers(CyberDNS *dns, const std::string &filename){ //adds computers to the server throgh "computers" xml
	ptree ptCp;
	read_xml(filename, ptCp);  //read from xml -> write to tree

	BOOST_FOREACH(ptree::value_type &v, ptCp.get_child("")) {  // run over the file  for each title
		if (v.first == "computer") {
			std::cout << "Adding to server: " << v.second.get<std::string>("name") << "\n";
			CyberPC * pc = new CyberPC(v.second.get<std::string>("os"), v.second.get<std::string>("name"));//create pc using the second title
			dns->CyberDNS::AddPC(*pc);
			std::cout<< v.second.get<std::string>("name") << " connected to server" << "\n";
		}
	}
}

void makeNetwork(CyberDNS *dns, const std::string &filename){ //connect between two computers in the server throgh "network" xml
	ptree ptCp;
	read_xml(filename, ptCp);  //read from xml -> write to tree

	BOOST_FOREACH(ptree::value_type &v, ptCp.get_child("")) {  // run over the file  for each title
		if (v.first == "wire") {
			std::cout << "connecting " << v.second.get<std::string>("pointA") << " to "<< v.second.get<std::string>("pointB") <<"\n";
			CyberPC& pcA=dns->CyberDNS::GetCyberPC(v.second.get<std::string>("pointA"));
			CyberPC& pcB=dns->CyberDNS::GetCyberPC(v.second.get<std::string>("pointB"));
			pcA.AddConnection(pcB.getName());
			pcB.AddConnection(pcA.getName());
		}
	}

}

void events(CyberDNS *dns, const std::string &filename){ //read and executes events throgh "events" xml
	ptree ptCp;
	read_xml(filename, ptCp);  //read from xml -> write to tree
	BOOST_FOREACH(ptree::value_type &v, ptCp.get_child("")) {  // run over the file  for each title


		if (v.first == "hack") {
			int wormDormancy = v.second.get<int>("wormDormancy");
			std::cout<<"Day "<< currentDay<<":" << "\n";
			std::cout <<"\t"<<"Hack occurred on " << v.second.get<std::string>("computer")<<"\n";
			CyberPC& pc=dns->CyberDNS::GetCyberPC(v.second.get<std::string>("computer"));
			CyberWorm* worm=new CyberWorm(v.second.get<std::string>("wormOs"), v.second.get<std::string>("wormName"), wormDormancy);
			pc.Infect(*worm);
			delete worm;
			dayRoutine(dns);
			currentDay++;
		}

		if (v.first == "clock-in") {
			int workTime = v.second.get<int>("workTime");
			int restTime=v.second.get<int>("restTime");
			int efficiency=v.second.get<int>("efficiency");

			std::cout<<"Day "<< currentDay<<":" << "\n";
			expertsList.push_back(new CyberExpert(v.second.get<std::string>("name"), workTime, restTime, efficiency));
			dayRoutine(dns);
			currentDay++;

		}
		if (v.first == "termination") {
			int time = v.second.get<int>("time");
			while(currentDay<= time){  //keep running the day routine of the experts without reading more events
				std::cout<<"Day "<< currentDay<<":" << "\n";
				dayRoutine(dns);
				currentDay++;
			}
			return;
		}
	}
}
void dayRoutine(CyberDNS *dns){ //daily experts and pc actions

	std::vector<CyberExpert*>::iterator itEx;
	std::vector<std::string>::iterator itPC=pcList.begin();
	pcList=dns->GetCyberPCList();
	bool hasFinished=false;
	for (itEx=expertsList.begin(); itEx!=expertsList.end(); ++itEx){ //runs over the experts vector
		for(int efficiency=(*itEx)->get_cyber_expert_efficiency() ; (*itEx)->getWorkTimeLeft()!=0 && efficiency>0 && !hasFinished; --efficiency){ //for each expert if he isn't on a break, examining computers by efficiency.
			std::cout<<"\t"<< (*itEx)->get_cyber_expert_name()<<" is examining " << *itPC << "\n";
			(*itEx)->CyberExpert::Clean(dns->CyberDNS::GetCyberPC(*itPC));
			++itPC;
			if (itPC==pcList.end()){
			  hasFinished=true;
			}
		}
		(*itEx)->dayPassed();
	}
	for(itPC=pcList.begin(); itPC!=pcList.end(); ++itPC){ // runs over the pc vector and execute "Run" function for each pc
		dns->CyberDNS::GetCyberPC(*itPC).Run(*dns);
	}
}


