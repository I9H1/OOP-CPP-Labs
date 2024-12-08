set(SOURCES
        FileReader.cpp
        CMDParser.cpp
        FileWriter.cpp
        ConfigParser.cpp
        Converters/ConverterFactory.cpp
        Converters/Mute.cpp
        Converters/Mix.cpp
        WAVReader.cpp
        WAVWriter.cpp)

set(HEADERS
        FileReader.h
        CMDParser.h
        FileWriter.h
        ConfigParser.h
        Exceptions.h
        Converters/ConverterFactory.h
        Converters/Mute.h
        Converters/Mix.h
        Converters/ConverterFactory.h
        Converters/Converter.h
        WAVReader.h
        WAVWriter.h
        WAVformat.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})