CXX = g++
CXXFLAGS = -std=c++17 -O2

SRC_DIR = src
BIN_DIR = bin
RESULTS_DIR = results

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/simulacion.cpp $(SRC_DIR)/graficar.cpp $(SRC_DIR)/animacion.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = $(BIN_DIR)/sim

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(RESULTS_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(EXEC)

run: all
	./$(EXEC)
