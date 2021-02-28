cmake_minimum_required(VERSION 3.17)
project(Jonny)

set(CMAKE_CXX_STANDARD 14)

add_executable(Jonny helloWorld.cpp)
add_executable(Euler PracticeNCNA/eulers.cpp)
add_executable(ProblemJ NCNARegional2020/ProblemJ.cpp)
add_executable(ProblemK NCNARegional2020/ProblemK.cpp)
add_executable(ProblemI NCNARegional2020/ProblemI.cpp)
add_executable(ProblemD NCNARegional2020/ProblemD.cpp)
add_executable(ProblemC NCNARegional2020/ProblemC.cpp)
add_executable(ProblemF NCNARegional2020/ProblemF.cpp)



