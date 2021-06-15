cmake_minimum_required(VERSION 3.15)
project(spark_store)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(inc)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES
    src/main.cpp
    resource/resource.qrc
    gui/spkwindow.cpp
    inc/spkwindow.h
    gui/spktitlebar.cpp
    inc/spktitlebar.h
    inc/spkui_general.h
    gui/spkui_general.cpp
    inc/deepinplatform.h
    src/spklogging.cpp
    inc/spklogging.h
    inc/spkuimsg.h
    src/spkuimsg.cpp
    inc/spkmainwindow.h
    inc/spkmsgbox.h
    gui/spkmsgbox.cpp
    inc/spkdialog.h
    gui/spkdialog.cpp
    inc/spkstore.h
    src/spkstore.cpp
    gui/spkmainwindow.cpp
    inc/spkpageqsstest.h
    gui/spkpageqsstest.cpp
    gui/spkcategoryselector.cpp
    inc/spkconfig.h
    src/telemetry/collectid.cpp
    )

include(cmake/FindLibNotify.cmake)
include(cmake/FindGlib.cmake)
include(cmake/FindGdk3.cmake)

include_directories(${GLIB_INCLUDE_DIRS})
include_directories(${GDK3_INCLUDE_DIRS})
set(LIBLINKING ${LIBLINKING}
    ${LIBNOTIFY_LIBRARIES}
    ${GLIB_LIBRARIES}
    ${GDK3_LIBRARIES}
    ${CMAKE_DL_LIBS})

# Required for a good backtrace
add_compile_options(-g)
add_link_options(-rdynamic)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} ${LIBLINKING})
