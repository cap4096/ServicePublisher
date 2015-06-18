cmake_minimum_required(VERSION 3.2)
project(ServiceAnnouncer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
set(SOURCE_FILES "${SOURCE_FILES} DnsResolver.cpp")
set(SOURCE_FILES "${SOURCE_FILES} HostAddress.cpp")

add_executable(test ${SOURCE_FILES} ServiceAnnouncer.cpp ServiceAnnouncer.h ServiceBrowser.cpp ServiceBrowser.h KeyValueEntry.cpp KeyValueEntry.h KeyValueContainer.cpp KeyValueContainer.h MessageBuffer.cpp MessageBuffer.h MessageBase.cpp MessageBase.h FindMessage.cpp FindMessage.h FindResponseMessage.cpp FindResponseMessage.h MessageFactory.cpp MessageFactory.h byte_order.h)