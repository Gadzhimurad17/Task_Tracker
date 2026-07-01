cmake_minimum_required(VERSION 3.28)
project(TaskManager)

# Включаем pkg-config для поиска системных библиотек в Linux
find_package(PkgConfig REQUIRED)
pkg_check_modules(SODIUM REQUIRED libsodium)
pkg_check_modules(PQXX REQUIRED libpqxx)

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
    src/models/entities/User.cpp

    # Repository
    src/models/repository/TaskCommentsRepo.cpp
    src/models/repository/ProjectsRepo.cpp
    src/models/repository/RolesRepo.cpp
    src/models/repository/TaskRepo.cpp
    src/models/repository/UserRepo.cpp

    # DataBaseManager
    src/models/repository/DatabaseManager.cpp

    # Authentication
    src/models/auth/SessionManager.cpp
    src/models/auth/PasswordHash.cpp

    # HistoryManager
    src/models/historymanager/ProjectsHistoryManager.cpp
    src/models/historymanager/HistoryManager.cpp

    # Services
    src/models/services/TaskService.cpp
    src/models/services/RolesService.cpp
    src/models/services/UserService.cpp
    src/models/services/ProjectsService.cpp
    src/models/services/CommentsService.cpp
    src/models/services/AuthService.cpp
)

set(HEADERS

    # Entities
    include/models/entities/Task.hpp
    include/models/entities/Projects.hpp
    include/models/entities/User.hpp
    include/models/entities/TaskComments.hpp
    include/models/entities/Roles.hpp

    # Repository
    include/models/repository/IRepository.hpp
    include/models/repository/ProjectsRepo.hpp
    include/models/repository/RolesRepo.hpp
    include/models/repository/TaskCommentsRepo.hpp
    include/models/repository/UserRepo.hpp
    include/models/repository/TaskRepo.hpp

    # DataBaseManager
    include/models/repository/DatabaseManager.hpp

    # Authentication
    include/models/auth/SessionManager.hpp
    include/models/auth/ISessionManager.hpp
    include/models/auth/AuthService.hpp
    include/models/auth/PasswordHash.hpp

    # HistoryManager
    include/models/historymanager/HistoryManager.hpp
    include/models/historymanager/IHistoryManager.hpp

    # Services
    include/models/services/IService.hpp
    include/models/services/TaskService.hpp
    include/models/services/RolesService.hpp
    include/models/services/CommentsService.hpp
    include/models/services/UserService.hpp
    include/models/services/ProjectsService.hpp
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_executable(TaskManager ${SOURCES} ${HEADERS})

# Добавляем пути к заголовочным файлам твоих библиотек
target_include_directories(TaskManager PUBLIC
    include
    ${SODIUM_INCLUDE_DIRS}
    ${PQXX_INCLUDE_DIRS}
)

target_compile_options(TaskManager PRIVATE -Wall -Wextra -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(TaskManager PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${SOURCES} ${HEADERS}
)

target_link_libraries(TaskManager
    Qt6::Widgets
    ${PQXX_LIBRARIES}
    ${SODIUM_LIBRARIES}
)
