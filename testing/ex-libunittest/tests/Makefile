lib_path=/usr/local/libunittest-9.3.5
sources="celsius_to_fahrenheit_test.cpp"
exec_name=c2f

all:
	g++ -std=c++14 -pthread -I . -I ../src -I $(lib_path)/include -lunittest -L $(lib_path)/lib $(sources) -o $(exec_name)

run: 
	LD_LIBRARY_PATH=$(lib_path)/lib/ ./$(exec_name)

