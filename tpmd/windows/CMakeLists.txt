# Software-based Trusted Platform Module (TPM) Emulator
# Copyright (C) 2004-2010 Mario Strasser <mast@gmx.net>
#
# $Id: CMakeLists.txt 404 2010-02-18 23:08:35Z mast $

include_directories("${PROJECT_SOURCE_DIR}/tpm")

file(GLOB tpmd_SRCS "*.[h|c]")
add_executable(tpmd ${tpmd_SRCS})
if(MTM_EMULATOR)
add_definitions(-DMTM_EMULATOR)
target_link_libraries(tpmd mtm tpm crypto)
else()
target_link_libraries(tpmd tpm crypto)
endif()
install(TARGETS tpmd RUNTIME DESTINATION .)

install(FILES control_tpmd.bat DESTINATION .)

