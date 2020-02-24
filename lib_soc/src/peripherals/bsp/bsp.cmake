if(NOT TARGET BSP_CMAKE)
add_library(BSP_CMAKE INTERFACE)

file(GLOB_RECURSE bsp_list "src/peripherals/bsp/**/*.cmake")

foreach(dev ${bsp_list})
    include(${dev})
    if(${DEVICE_NAME} EQUAL ${FULL} OR ${DEVICE_NAME} EQUAL ${BSP_ONLY})
        list(APPEND LIB_ADD_COMPILER_FLAGS ${DEVICE_ADD_COMPILER_FLAGS})
        list(APPEND LIB_XC_SRCS ${DEVICE_XC_SRCS})
        list(APPEND LIB_C_SRCS ${DEVICE_C_SRCS})
        list(APPEND LIB_INCLUDES ${DEVICE_INCLUDES})
        list(APPEND LIB_DEPENDENT_MODULES ${DEVICE_DEPENDENT_MODULES})
        list(APPEND LIB_OPTIONAL_HEADERS ${DEVICE_OPTIONAL_HEADERS})
        message("\tAdded ${DEVICE_NAME} bsp device for lib_soc")
    endif()
endforeach()
endif()
