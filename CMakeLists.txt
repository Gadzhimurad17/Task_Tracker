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

    # Entities
    src/models/entities/Task.cpp
    src/models/entities/Projects.cpp
    src/models/entities/TaskComments.cpp
    src/models/entities/Roles.cpp
    src/models/entities/Users.cpp

    # Repository
    src/models/repository/TaskCommentsRepo.cpp
    src/models/repository/ProjectsRepo.cpp
    src/models/repository/RolesRepo.cpp
    src/models/repository/TaskRepo.cpp
    src/models/repository/UsersRepo.cpp

    # DataBaseManager
    src/models/repository/DatabaseManager.cpp

    # Authentication
    src/models/auth/SessionManager.cpp

    # HistoryManager
    src/models/historymanager/ProjectsHistoryManager.cpp
    src/models/historymanager/HistoryManager.cpp

    # Services
    src/models/services/TaskService.cpp
    src/models/services/RolesService.cpp
    src/models/services/UsersService.cpp
    src/models/services/ProjectsService.cpp
    src/models/services/CommentsService.cpp
    src/models/services/AuthService.cpp
)

set(HEADERS

    # Entities
    include/models/entities/Task.hpp
    include/models/entities/Projects.hpp
    include/models/entities/Users.hpp
    include/models/entities/TaskComments.hpp
    include/models/entities/Roles.hpp

    # Repository
    include/models/repository/IRepository.hpp
    include/models/repository/ProjectsRepo.hpp
    include/models/repository/RolesRepo.hpp
    include/models/repository/TaskCommentsRepo.hpp
    include/models/repository/UsersRepo.hpp
    include/models/repository/TaskRepo.hpp

    # DataBaseManager
    include/models/repository/DatabaseManager.hpp

    # Authentication
    include/models/auth/SessionManager.hpp
    include/models/auth/ISessionManager.hpp

    # HistoryManager
    include/models/historymanager/HistoryManager.hpp
    include/models/historymanager/IHistoryManager.hpp
    include/models/historymanager/UsersHistoryManager.hpp

    # Services
    include/models/services/IService.hpp
    include/models/services/TaskService.hpp
    include/models/services/RolesService.hpp
    include/models/services/CommentsService.hpp
    include/models/services/UsersService.hpp
    include/models/services/ProjectsService.hpp
    include/models/services/AuthService.hpp
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
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
