
#---symbol export setting---
include(GenerateExportHeader)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
generate_export_header(${targetName}
        EXPORT_MACRO_NAME ${targetName}_EXPORT
        EXPORT_FILE_NAME ${targetName}Export.hpp)