# Plugin name
set(PLUGIN_NAME yrt-pet-csv)
project(${PLUGIN_NAME})

# Sources
set(PLUGIN_SOURCES CSVListMode.cpp)

set(PLUGIN_SOURCES_PYBIND11 pybind11_csv.cpp)

add_plugin_sources(${PLUGIN_SOURCES})
if(${BUILD_PYBIND11})
	add_pybind11_plugin_sources(${PLUGIN_SOURCES_PYBIND11})
endif()
