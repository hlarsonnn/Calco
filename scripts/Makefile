# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra
LDFLAGS := 
TARGET := calco

# Source files
SRCS := calco.cpp
OBJS := $(SRCS:.cpp=.o)

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
