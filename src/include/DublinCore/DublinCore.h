/*!
 * \author Henry Borchers
 * \version 1.0
 * \date 2017-6-24
 * \copyright GNU PUBLIC LICENSE
 *
 * \mainpage Dublin Core library
 * \section intro_sec Introduction
 * This is a simple library for building Dublin Core XML data.
 * \section purpose_sec Purpose
 * This is built for running tests.
 * \section build_sec Build The Library
 * How to build the library with CMake
 * \subsection step1 Setup
 * Create a build directory. As with all CMake projects, it's recommend to build in another folder.
 * \subsection step2 CMake configure
 * In the build directory, type "cmake" followed by the relative path to the root of the source.
 * \subsection step3 Compile
 * In the build directory, type "cmake --build ."
 */

#ifndef DUBLINCORE_LIBRARY_H
#define DUBLINCORE_LIBRARY_H

#include "Element.h"
#include "Root.h"
#include "Printer.h"
#include "Render.h"

/*!
 * \brief Prints hello to the standard output
 * \details This is a very silly and mostly useless function but it can be helpful to make sure that that code is being
 * executed.
 */
void hello();

#endif