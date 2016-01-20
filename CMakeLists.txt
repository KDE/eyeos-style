project(eyeos-style)
cmake_minimum_required(VERSION 2.8.11)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)
include(MacroLibrary)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(${KDE4_INCLUDES})


set(eyeosstyle_SRCS
    eyeosstyle.cpp
    eyeosstyleplugin.cpp
)
kde4_add_plugin(eyeos ${eyeosstyle_SRCS})
target_link_libraries(eyeos ${KDE4_KDEUI_LIBS})

install(TARGETS eyeos DESTINATION ${PLUGIN_INSTALL_DIR}/plugins/styles/)
install(FILES eyeos.themerc DESTINATION ${DATA_INSTALL_DIR}/kstyle/themes/)

