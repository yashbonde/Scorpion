We will be using some of the elements of google's style guide: https://google.github.io/styleguide/cppguide.html

===============================================================================================================

Header file Starting

/*
<header file name> header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file <description of this header file>

See license for legal queries.
<year>, <author(s)>
*/

#ifndef <PROJECT>_<PATH>_<FILE>_H_ --> #ifndef SCORPION_CORE_OPS_H_ means SCORPION project
in CORE path OPS file.

===============================================================================================================

Source code starting

/*
<source file name> source file for Scorpion Framework for <header name> header file,
written for Texas Instruments Launchpad devices and Arduino. This framework aims
to implement machine learning on small embedded devices.

This source file <description of this source file>

See license for legal queries.
<year>, <author(s)>
*/

===============================================================================================================

Class names are to be kept in camel coded style (first letter caps) --> ThisClass
Function names are to be kept in underscore style --> this_function
variable and const names are to have understandable underscore names --> shape_vec
global macros --> #define NUM_CORES 32

Use

//========= Public =========//

//========= Public <Class name> (if using nested class) =========//  

This is all the stuff in public of any class.

//========= Private =========//  

//========= Private <Class name> (if using nested class) =========//

This is all the stuff in private of any class. (must come after public)
