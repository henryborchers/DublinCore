cmake_minimum_required(VERSION 3.8)
project(DublinCore VERSION 0.0.1)
set(PROJECT_DESCRIPTION "Simple library that constructs Dublin Core XML data.")

find_package(Doxygen)

option(DublinCode_Generate_HTML_Documentation    "Build HTML formated Doxygen Documentation"     ${Doxygen_FOUND} )
option(DublinCode_Generate_MAN_Documentation     "Build MAN Page formate Doxygen Documentation"  OFF              )
option(DublinCode_Generate_RTF_Documentation     "Build RTF formated Doxygen Documentation"      OFF              )
option(DublinCode_Generate_LATEX_Documentation   "Build LATEX formated Doxygen Documentation"    OFF              )
option(DublinCode_Sample                         "Build sample runner program"                   ON               )

add_subdirectory(src)
add_subdirectory(runner)
add_subdirectory(tests)

if (Doxygen_FOUND)
    include(cmake/Doxygen.cmake)

    if (DublinCode_Generate_HTML_Documentation)
        build_HTML_docs()

    endif ()

    if (DublinCode_Generate_MAN_Documentation)
        build_MAN_docs()
    endif ()

    if (DublinCode_Generate_RTF_Documentation)
        build_RTF_docs()
    endif ()

    if (DublinCode_Generate_LATEX_Documentation)
        build_LATEX_docs()
    endif ()
endif ()

enable_testing()
add_test(NAME MY_TEST COMMAND my_tests)