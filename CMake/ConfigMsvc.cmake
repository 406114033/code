
#-------------------------------------------------------------------------------
# MSVC设置，需要在TargetName之后使用
if (TARGET ${TargetName})
    set(targetName ${TargetName})
endif()

if (WIN32 AND MSVC)
    target_link_options(${targetName} PUBLIC /SAFESEH:NO)
    target_compile_options(${targetName} PUBLIC "/utf-8")
    target_compile_options(${targetName} PUBLIC /MP)
    target_compile_options(${targetName} PUBLIC /Zi)
    set_target_properties(${targetName} PROPERTIES LINK_FLAGS "/INCREMENTAL:NO /DEBUG /OPT:REF")
    #set_target_properties(${targetName} PROPERTIES COMPILE_FLAGS "/wd4819") #code page (936)
    #set_target_properties(${targetName} PROPERTIES LINK_FLAGS "/INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF")
    #message(STATUS "MSVC settings opened.")
    # /OPT:REF 清除从未引用的函数和/或数据
endif ()