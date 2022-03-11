CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic
.PHONY : all
all : program

program : main.cpp LiveMusic.o StandUp.o Film.o
	$(CXX) $(CXXFLAGS) -o $@ $^

LiveMusic.o : LiveMusic.cpp LiveMusic.h
	$(CXX) $(CXXFLAGS) -c $<

StandUp.o : StandUp.cpp StandUp.h
	$(CXX) $(CXXFLAGS) -c $<

Film.o : Film.cpp Film.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean :
	$(RM) *.o
	$(RM) program