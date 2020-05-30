lib_path=/home/alex/projects/cpp/lib/googletest/googletest
exec_name=temp_conversion_test

CPPFLAGS += -I $(lib_path)/include
CXXFLAGS += -std=c++14

$(exec_name): main.cpp
	$(CXX) $(CPPFLAGS) -I . -I ../src -L $(lib_path)/lib/ $(CXXFLAGS) $^ \
	-lgtest -lpthread -o $@
