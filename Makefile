CXX = g++
CXXFLAGS = -Wall -std=c++17
CPPFLAGS = -Iinclude
TARGET = parkir

SOURCES = src/main.cpp src/data_parkir.cpp src/file_parkir.cpp src/menu_parkir.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

src/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean