lib_path=/usr/local/unittest-cpp
sources="main.cpp"
exec_name=temp_conversion_test

all:
	g++ -std=c++14 -pthread -I . -I ../src -I $(lib_path)/include -lUnitTest++ -L $(lib_path)/lib $(sources) -o $(exec_name)

run: 
	LD_LIBRARY_PATH=$(lib_path)/lib/ ./$(exec_name)
