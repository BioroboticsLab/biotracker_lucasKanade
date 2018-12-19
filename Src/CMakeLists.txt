##############################################################
#### Biotracker: lucaskanade
##############################################################

include(biotracker-utility/VSSugar)
VSSourceGroups(${CMAKE_CURRENT_LIST_DIR})

include(biotracker-utility/TrackerPlugin)

set(target biotracker-lucaskanade.bio_tracker)

add_behavior_plugin(${target}
    "PluginContext.cpp"
    "Config.cpp"
    "BioTrackerPlugin.cpp"
    "View/TrackedElementView.cpp"
    "View/TrackerParameterView.cpp"
    "Model/BioTrackerTrackingAlgorithm.cpp"
    "Model/null_Model.cpp"
    "Model/TrackerParameter.cpp"
    "Controller/ControllerTrackedComponent.cpp"
    "Controller/ControllerTrackingAlgorithm.cpp"
    "Controller/null_Controller.cpp"
)

install(TARGETS ${target} OPTIONAL DESTINATION .)