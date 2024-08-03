cmake_minimum_required(VERSION 3.27)
project(ATM_management_system_master)

set(CMAKE_CXX_STANDARD 14)

add_executable(ATM_management_system_master
        atm_management.cpp
        README.md
        AutoTellerMachine.cpp
        AutoTellerMachine.h
        ATMSystem.cpp
        ATMSystem.h)
