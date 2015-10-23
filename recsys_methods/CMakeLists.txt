# CmakeLists.txt in recsys_methods dir
ADD_SUBDIRECTORY(colaborative_filtring)
ADD_SUBDIRECTORY(content_based)

file(GLOB recsys_methods_SRC
    "*.h"
    "*.cpp"
)

ADD_LIBRARY(recsys_methods ${recsys_methods_SRC})
target_link_libraries(recsys_methods model)
