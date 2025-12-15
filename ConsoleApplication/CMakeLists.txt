cmake_minimum_required(VERSION 3.16)# 최소 cmake 3.16 버전 이상 요구

project(ConsoleApplication LANGUAGES CXX)## c++ 프로젝트임을 명시

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) ## c++ 버전이 너무 오래된 컴파일이면 오류 출력

#Qt에서 사용할 모듈 명시
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

#프로젝트에 추가할 소스코드 파일 명시
add_executable(ConsoleApplication
  main.cpp
)
target_link_libraries(ConsoleApplication PRIVATE Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS ConsoleApplication
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
