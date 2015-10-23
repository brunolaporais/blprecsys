# CmakeLists.txt in util dir

file(GLOB util_SRC
    "*.h"
    "*.cpp"
)


ADD_LIBRARY( util ${util_SRC})
target_link_libraries(util)
