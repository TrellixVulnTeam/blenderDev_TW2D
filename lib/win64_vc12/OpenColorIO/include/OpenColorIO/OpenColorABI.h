/*
Copyright (c) 2003-2010 Sony Pictures Imageworks Inc., et al.
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

#ifndef INCLUDED_OCIO_OPENCOLORABI_H
#define INCLUDED_OCIO_OPENCOLORABI_H

// Makefile configuration options
#define OCIO_NAMESPACE OpenColorIO
#define OCIO_USE_BOOST_PTR 1
#define OCIO_VERSION "1.0.8"
#define OCIO_VERSION_NS v1

/* Version as a single 4-byte hex number, e.g. 0x01050200 == 1.5.2
   Use this for numeric comparisons, e.g. #if OCIO_VERSION_HEX >= ... 
   Note: in the case where SOVERSION is overridden at compile-time,
   this will reflect the original API version number.
   */
#define OCIO_VERSION_HEX ((1 << 24) | \
                          (0 << 16) | \
                          (8 <<  8))


// Namespace / version mojo
#define OCIO_NAMESPACE_ENTER namespace OCIO_NAMESPACE { namespace OCIO_VERSION_NS
#define OCIO_NAMESPACE_EXIT using namespace OCIO_VERSION_NS; }
#define OCIO_NAMESPACE_USING using namespace OCIO_NAMESPACE;

// shared_ptr / dynamic_pointer_cast
#if OCIO_USE_BOOST_PTR
#include <boost/shared_ptr.hpp>
#define OCIO_SHARED_PTR boost::shared_ptr
#define OCIO_DYNAMIC_POINTER_CAST boost::dynamic_pointer_cast
#elif __GNUC__ >= 4
#include <tr1/memory>
#define OCIO_SHARED_PTR std::tr1::shared_ptr
#define OCIO_DYNAMIC_POINTER_CAST std::tr1::dynamic_pointer_cast
#else
#error OCIO needs gcc 4 or later to get access to <tr1/memory> (or specify USE_BOOST_PTR instead)
#endif

// If supported, define OCIOEXPORT, OCIOHIDDEN
// (used to choose which symbols to export from OpenColorIO)
#if defined __linux__ || __APPLE__
    #if __GNUC__ >= 4
        #define OCIOEXPORT __attribute__ ((visibility("default")))
        #define OCIOHIDDEN __attribute__ ((visibility("hidden")))
    #else
        #define OCIOEXPORT
        #define OCIOHIDDEN
    #endif
#elif defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS) || defined(_MSC_VER)
    // Windows requires you to export from the main library and then import in any others
    #if defined OpenColorIO_EXPORTS
        #define OCIOEXPORT __declspec(dllexport)
    #else
        #define OCIOEXPORT __declspec(dllimport)
    #endif
    #define OCIOHIDDEN
#else // Others platforms not supported atm
    #define OCIOEXPORT
    #define OCIOHIDDEN
#endif

#endif // INCLUDED_OCIO_OPENCOLORABI_H
