CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g

TARGET := main
SRC := \
    main.cpp \
    source/data_structures/string/String.cpp \
    source/data_structures/bitset/BitSet.cpp \
    source/events/еlementary_еvent/ЕlementaryEvent.cpp \
    source/events/set_of_elementary_events/SetOfElementaryEvents.cpp \
    source/sigma_algebra/SigmaAlgebra.cpp \
    source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
