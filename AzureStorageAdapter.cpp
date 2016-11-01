#include "AzureStorageAdapter.h"
long AzureStorageAdapter::getSize(FilePath *filePath)
{
    syslog(LOG_INFO, "AzureStorageAdapter::getSize %s %s\n", filePath->directory, filePath->fileName);
    azure::storage::cloud_blob_container container = blob_client->get_container_reference(_XPLATSTR(filePath->directory));
    if (container.exists())
    {
        syslog(LOG_INFO, "AzureStorageAdapter::getSize2\n");
        azure::storage::cloud_block_blob blob1 = container.get_block_blob_reference(_XPLATSTR(filePath->fileName));
        blob1.download_attributes();
        syslog(LOG_INFO, "AzureStorageAdapter::getSize3\n");
        return blob1.properties().size();
    }
    else
    {
        return 0;
    }
}