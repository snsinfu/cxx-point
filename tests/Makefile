OPTFLAGS = \
  -O2

DBGFLAGS = \
  -g \
  -fsanitize=address

CXXFLAGS = \
  -std=c++11 \
  -pedantic \
  -Wall \
  -Wextra \
  -Wconversion \
  -Wsign-conversion \
  -Wshadow \
  $(OPTFLAGS) \
  $(DBGFLAGS) \
  $(INCLUDES)

OBJECTS = \
  main.o \
  coordinates_test.o \
  vector_test.o \
  point_test.o

ARTIFACTS = \
  $(OBJECTS) \
  *.dSYM \
  main

.SUFFIXES: .cc
.PHONY: test clean

test: main
	@./main

clean:
	rm -rf $(ARTIFACTS)

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

main.o: catch.hpp
coordinates.o: catch.hpp ../include/point.hpp
vector.o: catch.hpp ../include/point.hpp
point.o: catch.hpp ../include/point.hpp
