cmake_minimum_required(VERSION 3.12)

exec_program("git" ${CMAKE_CURRENT_SOURCE_DIR} ARGS "describe --tags --abbrev=0" OUTPUT_VARIABLE GIT_TAG)

project(BT_lukaskanade.tracker)

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    option(PACKAGE_WINDOWS_MSI "Create .msi package" OFF)
endif()
option(PACKAGE_TXZ "Create .tar.xz package" OFF)

find_package(BT_Utility 0.1.1 REQUIRED)

add_subdirectory(Src)

set(CPACK_PACKAGE_NAME "BioTracker Plugin LukasKanade")
set(CPACK_PACKAGE_VENDOR "Biorobotics Lab / FU Berlin")

set(CPACK_PACKAGE_VERSION ${GIT_TAG})

if(PACKAGE_WINDOWS_MSI)
    set(CPACK_GENERATOR "WIX")
    set(CPACK_WIX_UPGRADE_GUID "f3dd97dc-0b5e-411c-a991-4c7d423c06af")

    set(CPACK_PACKAGE_INSTALL_DIRECTORY "RoboFish/BioTracker/Plugins")

    set(CPACK_WIX_PROGRAM_MENU_FOLDER "RoboFish")
elseif(PACKAGE_TXZ)
    set(CPACK_GENERATOR "TXZ")
endif()

include(CPack)
