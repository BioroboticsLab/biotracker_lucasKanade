##############################################################
#### Biotracker: LukasKanade
##############################################################

include(BT_Utility/VSSugar)
VSSourceGroups(${CMAKE_CURRENT_LIST_DIR})

set(TN bt_lukaskanade.bio_tracker)
include(BT_Utility/TrackerPlugin)

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
