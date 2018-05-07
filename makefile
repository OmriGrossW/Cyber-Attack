
# All Targets
all: cyber

# Tool invocations
# Executable "cyber" depends on the files main.o CyberDNS.o CyberExpert.o CyberPC.o CyberWorm.o
cyber: bin/main.o bin/CyberDNS.o bin/CyberExpert.o bin/CyberPC.o bin/CyberWorm.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cyber bin/main.o bin/CyberDNS.o bin/CyberExpert.o bin/CyberPC.o bin/CyberWorm.o
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/CyberDNS.o: src/CyberDNS.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/CyberDNS.o src/CyberDNS.cpp

# Depends on the source and header files
bin/CyberExpert.o: src/CyberExpert.cpp
	g++ -g -Wall -c -Linclude -o bin/CyberExpert.o src/CyberExpert.cpp

# Depends on the source and header files
bin/CyberPC.o: src/CyberPC.cpp
	g++ -g -Wall -c -Linclude -o bin/CyberPC.o src/CyberPC.cpp

# Depends on the source and header files
bin/CyberWorm.o: src/CyberWorm.cpp
	g++ -g -Wall -c -Linclude -o bin/CyberWorm.o src/CyberWorm.cpp
	
# Depends on the source and header files 
bin/main.o: src/main.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/main.o src/main.cpp

#Clean the build directory
clean: 
	rm -f bin/*