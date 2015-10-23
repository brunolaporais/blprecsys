# CmakeLists.txt in content_based dir

file(GLOB cb_SRC
    "*.h"
    "*.cpp"
)

ADD_LIBRARY(cb ${cb_SRC})
target_link_libraries(cb recsys_methods model)