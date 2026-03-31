find_package(PkgConfig REQUIRED)
cmake_minimum_required(VERSION 4.3.1)

project(TaskManager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    src/main.cpp
    src/TaskManager.cpp
    src/Task.cpp
    # src/repository/PostgresTask.cpp
    src/historymanager/HistoryManager.cpp
)

set(HEADERS
    include/Task.hpp
    include/TaskManager.hpp
    # include/repository/ITaskRepository.hpp
    # include/repository/PostgresTask.hpp
    include/historymanager/HistoryManager.hpp
)

add_executable(TaskManager ${SOURCES}  ${HEADERS})

target_compile_options(TaskManager PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(TaskManager PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${SOURCES} ${HEADERS}
)

pkg_check_modules(PQXX REQUIRED libpqxx)
