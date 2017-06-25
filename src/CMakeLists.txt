project(DublinCore VERSION 0.0.1)
# List public headers to be used so that they install

set(PUBLIC_HEADERS
        ${PROJECT_SOURCE_DIR}/include/DublinCore/DublinCore.h
        ${PROJECT_SOURCE_DIR}/include/DublinCore/Element.h
        ${PROJECT_SOURCE_DIR}/include/DublinCore/Printer.h
        ${PROJECT_SOURCE_DIR}/include/DublinCore/Root.h
        )

set(targets_export_name "${PROJECT_NAME}Targets")

# Add library source headers
add_library(DublinCore
        DublinCore.cpp
        Element.cpp
        Root.cpp
        Printer.cpp
        )

# Make an alias so it works exactly the same when including it as a subproject
add_library(DublinCore::DublinCore ALIAS DublinCore)

# Set the library to the correct version of C/CPP and set the public headers so they're installed later
set_target_properties(DublinCore PROPERTIES
        CXX_STANDARD 14
        PUBLIC_HEADER "${PUBLIC_HEADERS}"
        )

# set the include path for the library
target_include_directories(DublinCore

        # Public headers that are included with project when used elsewhere
        PUBLIC
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/DublinCore>
            $<INSTALL_INTERFACE:include>

        # Headers only being used by this library
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
        )

include(CMakePackageConfigHelpers)

set(INCLUDE_INSTALL_DIR include/)

# Write the basic configureation information about the package
configure_package_config_file(
        "../cmake/Config.cmake.in"
        "${PROJECT_BINARY_DIR}/DublinCoreConfig.cmake"
        INSTALL_DESTINATION lib/cmake/DublinCore
        PATH_VARS INCLUDE_INSTALL_DIR

)

# Write the basic version information about the package
write_basic_package_version_file(
        "${PROJECT_BINARY_DIR}/DublinCoreConfigVersion.cmake"
        COMPATIBILITY SameMajorVersion
)


install(FILES
            ${PROJECT_BINARY_DIR}/DublinCoreConfigVersion.cmake
            ${PROJECT_BINARY_DIR}/DublinCoreConfig.cmake
        DESTINATION
            lib/cmake/DublinCore)


# install the target files to the correct components
install(TARGETS DublinCore EXPORT DublinCoreTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include/DublinCore
        )

# Install the information about the targets
install(EXPORT DublinCoreTargets
        FILE DublinCoreTargets.cmake
        NAMESPACE DublinCore::
        DESTINATION lib/cmake/DublinCore
        )
