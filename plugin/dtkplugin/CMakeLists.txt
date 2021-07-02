set(PLUGIN_SOURCE
	spkdtkplugin.h
	spkdtkplugin_impl.h
        spkdtkplugin.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(dtkwidget REQUIRED IMPORTED_TARGET dtkwidget)
pkg_check_modules(dtkgui REQUIRED IMPORTED_TARGET dtkgui)
pkg_check_modules(dtkcore REQUIRED IMPORTED_TARGET dtkcore)
add_library(spkdtkplugin SHARED ${PLUGIN_SOURCE})

target_link_libraries(spkdtkplugin PkgConfig::dtkwidget PkgConfig::dtkgui PkgConfig::dtkcore ${REQUIRED_LIBS_QUALIFIED})

install(TARGETS spkdtkplugin LIBRARY DESTINATION lib)
