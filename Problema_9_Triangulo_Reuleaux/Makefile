CXX = g++
CXXFLAGS = -std=c++17 -O2

SRC_DIR = src
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/simulacion.cpp $(SRC_DIR)/graficar.cpp $(SRC_DIR)/animacion.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

TARGET = $(BIN_DIR)/sim

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)
