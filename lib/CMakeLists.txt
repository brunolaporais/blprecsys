# CmakeLists.txt in lib dir

file(GLOB lib_SRC
    "*.h"
    "*.cpp"
)


ADD_LIBRARY( lib ${lib_SRC})
target_link_libraries(lib)