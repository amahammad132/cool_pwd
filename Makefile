CC = clang
CXX = clang++
PROG = pwd
OBJ = $(PROG).o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -std=c++20 -o $@ $<

$(PROG): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(PROG) $(PROG).o
