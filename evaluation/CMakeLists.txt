# CmakeLists.txt in evaluation dir
file(GLOB validation_SRC
    "*.h"
    "*.cpp"
)

ADD_LIBRARY(validation ${validation_SRC})
target_link_libraries(validation model cf cb file_operation)
