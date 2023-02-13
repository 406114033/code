

set(DEPLOY_OSX_VERSION 10.13)

if(ProductName STREQUAL "")
    set(ProductName ${TargetName})
endif()

#-------------------------------------------------------------------------------
# Xcode Project Config
if(APPLE)
    set(MACOSX_BUNDLE_BUNDLE_NAME ${ProductName})
    set(MACOSX_BUNDLE_ICON_FILE AppIcon)
    set(MACOSX_BUNDLE_INFO_STRING ${ProductName})
    set(MACOSX_BUNDLE_COPYRIGHT "${ProductName} 2020 © All Right Reserved.")
    set(MACOSX_DEPLOYMENT_TARGET ${DEPLOY_OSX_VERSION})


    set_target_properties(${TargetName} PROPERTIES
            XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET ${DEPLOY_OSX_VERSION}
            XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
            MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Resources/Info.plist.in
            )
endif ()
