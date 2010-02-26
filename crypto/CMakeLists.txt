# Software-based Trusted Platform Module (TPM) Emulator
# Copyright (C) 2004-2010 Mario Strasser <mast@gmx.net>
#
# $Id: CMakeLists.txt 364 2010-02-11 10:24:45Z mast $

file(GLOB crypto_SRCS "*.[h|c]")
add_library(crypto STATIC ${crypto_SRCS})
target_link_libraries(crypto gmp)

