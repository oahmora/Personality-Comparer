CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
   src/unit_test.cpp
   src/createBirthday.cpp
   src/date.cpp
   src/actualZodiac.cpp
   src/behavior.cpp
)

ADD_EXECUTABLE(main
   main.cpp
   src/createBirthday.cpp
   src/date.cpp
   src/actualZodiac.cpp
   src/behavior.cpp 
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
