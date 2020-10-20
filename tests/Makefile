OPTFLAGS = \
  -O2

CXXFLAGS = \
  -std=c++11 \
  -pedantic \
  -Wall \
  -Wextra \
  -Wconversion \
  -Wsign-conversion \
  -Wshadow \
  $(OPTFLAGS)

OBJECTS = \
  main.o \
  coordinates_test.o \
  vector_test.o \
  point_test.o \
  matrix_test.o

ARTIFACTS = \
  $(OBJECTS) \
  main

.SUFFIXES: .cc
.PHONY: test clean

test: main
	@./main

clean:
	rm -f $(ARTIFACTS)

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

main.o: catch.hpp
coordinates_test.o: catch.hpp ../include/point.hpp
vector_test.o: catch.hpp ../include/point.hpp
point_test.o: catch.hpp ../include/point.hpp
matrix_test.o: catch.hpp ../include/point.hpp
