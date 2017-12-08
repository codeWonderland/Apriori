cmake_minimum_required(VERSION 3.9)
project(fa17_csi281_decosta_easter)

set(CMAKE_CXX_STANDARD 11)

add_executable(fa17_csi281_decosta_easter
        Models/Association.cpp
        Models/Association.h
        Models/circularQueue.h
        Models/Frequency.cpp
        Models/Frequency.h
        Models/Itemset.cpp
        Models/Itemset.h
        Models/linkedList.h
        Models/Node.h
        AprioriFunctions.cpp
        AprioriFunctions.h
        main.cpp
        sortingFunction.h)
