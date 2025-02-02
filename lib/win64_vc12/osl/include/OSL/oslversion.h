/*
Copyright (c) 2009-2011 Sony Pictures Imageworks Inc., et al.
All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
* Neither the name of Sony Pictures Imageworks nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef OSLVERSION_H
#define OSLVERSION_H


// Versions.  There are three different sets of version numbers:
// (a) The version of the OSL language specification itself, i.e.,
//     what is OSL syntax, semantics, and standard library.
// (b) The version of the OSL library, i.e., this very software whose
//     source code you are reading.
// (c) The version of the .oso file format that this library uses
//     for compiled shaders.
// These are all independent, though loosely coupled.

// Version of this library:
#define OSL_LIBRARY_VERSION_MAJOR 1
#define OSL_LIBRARY_VERSION_MINOR 7
#define OSL_LIBRARY_VERSION_PATCH 1
#define OSL_LIBRARY_VERSION_RELEASE_TYPE 

#define OSL_LIBRARY_VERSION_CODE (10000 * OSL_LIBRARY_VERSION_MAJOR + \
                                    100 * OSL_LIBRARY_VERSION_MINOR + \
                                          OSL_LIBRARY_VERSION_PATCH)

// Magic macros to make OSL_LIBRARY_VERSION_STRING that looks like "1.2.3"
#define OSL_MAKE_VERSION_STRING2(a,b,c,d) #a "." #b "." #c #d
#define OSL_MAKE_VERSION_STRING(a,b,c,d) OSL_MAKE_VERSION_STRING2(a,b,c,d)
#define OSL_LIBRARY_VERSION_STRING \
    OSL_MAKE_VERSION_STRING(OSL_LIBRARY_VERSION_MAJOR, \
                            OSL_LIBRARY_VERSION_MINOR, \
                            OSL_LIBRARY_VERSION_PATCH, \
                            OSL_LIBRARY_VERSION_RELEASE_TYPE)
#define OSL_INTRO_STRING "OpenShadingLanguage " OSL_LIBRARY_VERSION_STRING
#define OSL_COPYRIGHT_STRING "(c) Copyright 2009-2014 Sony Pictures Imageworks, et al. All rights reserved."


// Version numbers for the compiled shader format.  The major number
// should only be changed if old .oso files should not be expected to
// work with current versions of the library (this should be EXTREMELY
// rare, hopefully never).  The minor number may be changed if newly
// compiled shaders won't work for old libraries, which sometimes
// happens but still should not be often.  Adding a new hint or a new
// shader instruction is not considered a change to the file format!
#define OSO_FILE_VERSION_MAJOR 1
#define OSO_FILE_VERSION_MINOR 0


// Symbols documenting specific API or other changes
#define OSL_SUPPORTS_WEIGHTED_CLOSURE_COMPONENTS 1
#define OSL_SHADERGLOBALS_HAS_RENDERER_PTR 1


#ifdef OSL_NAMESPACE
// Macros to use in each file to enter and exit the right name spaces.
#define OSL_NAMESPACE_ENTER namespace OSL_NAMESPACE { namespace OSL {
#define OSL_NAMESPACE_EXIT }; }; using namespace OSL_NAMESPACE;
#else
#define OSL_NAMESPACE_ENTER namespace OSL {
#define OSL_NAMESPACE_EXIT };
#endif

/// OSL_BUILD_CPP11 will be 1 if this OSL was built using C++11
#define OSL_BUILD_CPP11 0
/// OSL_BUILD_USELIBPLUSPLUS will be 1 if this OSL was built using libc++
#define OSL_BUILD_LIBCPLUSPLUS 0

#endif /* OSLVERSION_H */
