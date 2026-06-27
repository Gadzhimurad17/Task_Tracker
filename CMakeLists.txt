find_package(PkgConfig REQUIRED)

cmake_minimum_required(VERSION 3.28)

project(TaskManager)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(SOURCES
    src/main.cpp

    # src/models/TaskManager.cpp
    src/models/entities/Task.cpp
    src/models/entities/Projects.cpp
    src/models/entities/TaskComments.cpp
    src/models/entities/Roles.cpp
    src/models/entities/Users.cpp

    # src/view/View.cpp
    # src/view/SideBar.cpp

    # src/repository/PostgresTask.cpp
    # src/controllers/Controller.cpp
    # src/models/historymanager/HistoryManager.cpp
    src/models/repository/TaskCommentsRepo.cpp
    src/models/repository/ProjectsRepo.cpp
    src/models/repository/RolesRepo.cpp
    src/models/repository/DatabaseManager.cpp
    src/models/historymanager/HistoryManager.cpp

    src/models/services/TaskService.cpp

    src/models/repository/TaskRepo.cpp
    src/models/repository/UsersRepo.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(HEADERS
    include/models/entities/Task.hpp

    # include/models/TaskManager.hpp
    # include/view/View.hpp
    # include/view/SideBar.hpp
    include/models/repository/IRepository.hpp
    include/models/repository/ProjectsRepo.hpp
    include/models/repository/RolesRepo.hpp
    include/models/repository/TaskCommentsRepo.hpp
    include/models/repository/UsersRepo.hpp

    include/models/historymanager/HistoryManager.hpp
    include/models/historymanager/IHistoryManager.hpp
    include/models/services/IService.hpp
    include/models/services/TaskService.hpp

    # include/models/historymanager/Undo.hpp
    include/models/entities/Projects.hpp
    include/models/entities/Users.hpp
    include/models/entities/TaskComments.hpp
    include/models/entities/Roles.hpp
    include/models/repository/DatabaseManager.hpp
    include/models/exceptions/CustomExceptions.hpp

    include/models/repository/TaskRepo.hpp
)

add_executable(TaskManager ${SOURCES} ${HEADERS})

target_include_directories(TaskManager PUBLIC
    include
)
target_compile_options(TaskManager PRIVATE -Wall -Wextra -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(TaskManager PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${SOURCES} ${HEADERS}
)
pkg_check_modules(PQXX REQUIRED libpqxx)
target_link_libraries(TaskManager
    Qt6::Widgets
    ${PQXX_LIBRARIES}
)
