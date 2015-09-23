# CmakeLists.txt in colaborative_filtring dir

file(GLOB cf_SRC
    "*.h"
    "*.cpp"
)

ADD_LIBRARY(cf ${cf_SRC})
target_link_libraries(cf recsys_methods model)