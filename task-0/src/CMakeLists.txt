set(SOURCES
        FileReader.cpp
        FileWriter.cpp
        Statistics.cpp
        Tokenizer.cpp)

set(HEADERS
        FileReader.h
        FileWriter.h
        Statistics.h
        Tokenizer.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})