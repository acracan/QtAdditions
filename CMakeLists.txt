cmake_minimum_required(VERSION 3.7.0)

project(QtAdditions)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Qt 5 stuff

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)

# QtAdditions

add_library(QtAdditions
   README.md
   src/QHeaderViewWithWidgets.cpp   include/dak/QtAdditions/QHeaderViewWithWidgets.h
   src/QtUtilities.cpp              include/dak/QtAdditions/QtUtilities.h
   src/QWidgetListItem.cpp          include/dak/QtAdditions/QWidgetListItem.h
   src/QWidgetScrollListWidget.cpp  include/dak/QtAdditions/QWidgetScrollListWidget.h
   src/QWidgetListWidget.cpp        include/dak/QtAdditions/QWidgetListWidget.h
   src/QTableWidgetWithComboBox.cpp include/dak/QtAdditions/QTableWidgetWithComboBox.h
                                    include/dak/QtAdditions/QWidgetListMimeData.h
)

target_compile_features(QtAdditions PUBLIC
   cxx_std_20
)

target_include_directories(QtAdditions PUBLIC
   include
)

target_include_directories(QtAdditions PUBLIC
   "${Qt6Core_INCLUDE_DIRS}"
   "${Qt6Widgets_INCLUDE_DIRS}"
   "${Qt6Gui_INCLUDE_DIRS}"
)

add_subdirectory(examples/ExampleTableWithCombo EXCLUDE_FROM_ALL)
add_subdirectory(examples/ExampleWidgetList EXCLUDE_FROM_ALL)
add_subdirectory(examples/ExampleListHeaderWidget EXCLUDE_FROM_ALL)

