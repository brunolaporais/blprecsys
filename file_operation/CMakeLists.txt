# CmakeLists.txt in file_operation dir

file(GLOB file_operation_SRC
    "*.h"
    "*.cpp"
)


ADD_LIBRARY( file_operation ${file_operation_SRC})
target_link_libraries(file_operation model)
