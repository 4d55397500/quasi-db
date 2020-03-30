cmake_minimum_required(VERSION 3.12)
project(db_index)

set(CMAKE_CXX_STANDARD 98)


add_executable(db_index main.c tnode.c db.c index.c)




