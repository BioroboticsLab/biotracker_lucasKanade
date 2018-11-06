##############################################################
#### Biotracker: LukasKanade
##############################################################

set(TN bt_lukaskanade.bio_tracker)

if( CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR )
    include(BT_Utility/VSSugar)
    include(BT_Utility/TrackerPlugin)
else()
    include(${BT_Utility_SOURCE_DIR}/cmake/VSSugar.cmake)
    include(${BT_Utility_SOURCE_DIR}/cmake/TrackerPlugin.cmake)
endif()

VSSourceGroups(${CMAKE_CURRENT_LIST_DIR})

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
set_target_properties(${TN} PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON)

install(TARGETS ${TN} OPTIONAL DESTINATION .)

target_sources(${TN}
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/PluginContext.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Config.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/BioTrackerPlugin.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/View/TrackedElementView.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/View/TrackerParameterView.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Model/BioTrackerTrackingAlgorithm.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Model/null_Model.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Model/TrackerParameter.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Controller/ControllerTrackedComponent.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Controller/ControllerTrackingAlgorithm.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Controller/null_Controller.cpp"
)
