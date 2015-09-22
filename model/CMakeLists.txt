# CmakeLists.txt in Controller dir

file(GLOB model_SRC
    "*.h"
    "*.cpp"
)


ADD_LIBRARY( model ${model_SRC})
target_link_libraries(model)
