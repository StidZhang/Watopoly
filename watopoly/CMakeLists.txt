cmake_minimum_required(VERSION 3.5)
project(watopoly)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cc GameBoard.cc GameBoard.h Controller.cc Controller.h Cell.cc Cell.h Building.cc Building.h NonProperty.cc NonProperty.h AcademicBuilding.cc AcademicBuilding.h Residence.cc Residence.h Gym.cc Gym.h OSAP.cc OSAP.h TimsLine.cc TimsLine.h SLC.cc SLC.h GooseNesting.cc GooseNesting.h Tuition.cc Tuition.h CoopFee.cc CoopFee.h NeedlesHall.cc NeedlesHall.h GoToTim.cc GoToTim.h Player.cc Player.h Display.cc Display.h Observer.cc Observer.h Dice.cc Dice.h)
add_executable(watopoly ${SOURCE_FILES})