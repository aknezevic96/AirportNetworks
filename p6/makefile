knezevi2Proj6: knezevi2Proj6.o airport.o mylist.o mynode.o
	g++ -std=c++11 -o knezevi2Proj6 knezevi2Proj6.o airport.o mylist.o mynode.o
	
knezevi2Proj6.o: knezevi2Proj6.cpp networks.h airport.h mylist.h mynode.h
	g++ -std=c++11 -c knezevi2Proj6.cpp
	
airport.o: airport.cpp networks.h airport.h mylist.h mynode.h
	g++ -std=c++11 -c airport.cpp
	
mylist.o: mylist.cpp networks.h airport.h mylist.h mynode.h
	g++ -std=c++11 -c mylist.cpp
	
mynode.o: mynode.cpp networks.h airport.h mylist.h mynode.h
	g++ -std=c++11 -c mynode.cpp
	
clean:
	rm knezevi2Proj6.o airport.o mylist.o mynode.o knezevi2Proj6