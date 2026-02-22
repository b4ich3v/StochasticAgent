CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g -I.

TARGET := main

SRC := \
	main.cpp \
	source/data_structures/string/String.cpp \
	source/data_structures/bitset/BitSet.cpp \
	source/data_structures/combinatorics/factoriel/Factoriel.cpp \
	source/data_structures/combinatorics/k_selection/KSelection.cpp \
	source/events/elementary_event/ElementaryEvent.cpp \
	source/events/set_of_elementary_events/SetOfElementaryEvents.cpp \
	source/events/set_of_elementary_events/event/Event.cpp \
	source/sigma_algebra/SigmaAlgebra.cpp \
	source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.cpp \
	source/functions/probability_function/ProbabilityFunction.cpp \
	source/distributions/discrete_distributions/bernoulii/Bernoulli.cpp \
	source/distributions/discrete_distributions/binomial/Binomial.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
