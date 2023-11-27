CXX = g++            # C++ compiler
CXXFLAGS = -std=c++11 # Compilation flags
SRC = ACT_5.1_HASHING.cpp        # Replace with your C++ source file
OUTPUT = ACT_5.1_HASHING         # Replace with your desired executable name

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(SRC)

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)