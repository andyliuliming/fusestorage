# Find the AZURE_STORAGE includes and library
#
#  AZURE_STORAGE_WAS_INCLUDE_DIR - where to find blob.h, etc.
#  AZURE_STORAGE_WAS_CORE_INCLUDE_DIR - where to find blobstreams.h, etc.
#  AZURE_STORAGE_LIBRARIES   - List of libraries when using FUSE.
#  AZURE_STORAGE_FOUND       - True if FUSE lib is found.
# check if already in cache, be silent
IF (AZURE_STORAGE_WAS_INCLUDE_DIR)
    SET (AZURE_STORAGE_FIND_QUIETLY TRUE)
ENDIF (AZURE_STORAGE_WAS_INCLUDE_DIR)



# find includes
FIND_PATH (AZURE_STORAGE_WAS_INCLUDE_DIR blob.h
        ./azure-storage-cpp/Microsoft.WindowsAzure.Storage/includes/was
        )

FIND_PATH (AZURE_STORAGE_WAS_CORE_INCLUDE_DIR blobstreams.h
        ./azure-storage-cpp/Microsoft.WindowsAzure.Storage/includes/wascore
        )

mark_as_advanced (AZURE_STORAGE_WAS_INCLUDE_DIR AZURE_STORAGE_WAS_CORE_INCLUDE_DIR)