              cmake_minimum_required(VERSION 3.15) # cmake最低版本

              project(OJ)

              set(CMAKE_CXX_STANDARD 14)      # c++版本

              # include_directories(文件名)      # 如果有文件夹的话

              add_executable(OJ
                      E5-2.cpp) # 例如: Part1/Assignment.cpp, 如果没有上级文件夹，直接写文件名就行了
