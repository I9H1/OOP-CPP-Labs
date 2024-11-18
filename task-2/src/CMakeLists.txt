set(SOURCES
        Universe.cpp
        Game.cpp
        FileReader.cpp
        FileWriter.cpp)

set(HEADERS
        Universe.h
        Game.h
        FileReader.cpp
        FileReader.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})