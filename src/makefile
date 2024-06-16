CXX = g++
CXXFLAGS = -Wall -std=c++14
LDFLAGS = -lncursesw

SOURCES = main.cpp \
          Credit.cpp \
          Gate.cpp \
          Item.cpp \
          Map.cpp \
          Mission.cpp \
          Score.cpp \
          ScoreBoard.cpp \
          Snake.cpp \
          SnakeGame.cpp \
          StageManager.cpp

HEADERS = Credit.h \
          Gate.h \
          Item.h \
          Map.h \
          Mission.h \
          Score.h \
          ScoreBoard.h \
          Snake.h \
          SnakeGame.h \
          StageManager.h

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = snake

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

rebuild: clean all

.PHONY: all clean rebuild

