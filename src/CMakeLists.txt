

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
CMAKE_POLICY(SET CMP0007 NEW)

SET(LIBRARY_NAME    platform)

PROJECT(${LIBRARY_NAME} C)

SET(PROJECT_DESCRIPTION     "EBS Platform Interfaces")
SET(PROJECT_AUTHOR_NAME     "Chintalagiri Shashank")
SET(PROJECT_AUTHOR_EMAIL    "shashank.chintalagiri@gmail.com")
SET(PROJECT_LICENSE         "GPLv3")
SET(PROJECT_VERSION_MAJOR   0)
SET(PROJECT_VERSION_MINOR   1)
SET(PROJECT_VERSION_PATCH   0)
SET(PROJECT_VERSION_TWEAK   0)

INCLUDE(ebs/lib-conf)

FILE(GLOB_RECURSE SOURCES *.c)
FILE(GLOB_RECURSE HEADERS *.h)

IF(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    # This library is a quick hack to just get some shared header files into 
    # the platform packages tree. It should instead use a CMAKE Interface 
    # library.  We're not doing that right now because the approach is not 
    # currently compatible with the rest of the build architecture. While 
    # these headers will be used in the HAL and therefore are somewhat 
    # unavoidable, be very wary when using this 'library'. Avoid it if at 
    # all possible at the library level.
    
    # ADD_LIBRARY(platform INTERFACE)
    # TARGET_INCLUDE_DIRECTORIES(platform INTERFACE ${PUBLIC_INCLUDE_DIRECTORY})
    INSTALL_FILE_TREE(include/${LIBRARY_NAME} ${HEADERS})
    INCLUDE(ebs/lib-doc)
ENDIF()
