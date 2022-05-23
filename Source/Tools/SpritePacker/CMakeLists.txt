# Copyright (c) 2008-2022 the Urho3D project
# License: MIT

# Define target name
set (TARGET_NAME SpritePacker)

# Define source files
define_source_files ()

# Setup target
setup_executable (TOOL)

set_property(TARGET ${TARGET_NAME} PROPERTY FOLDER "Tools")
