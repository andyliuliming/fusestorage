#ifndef azure_storage_adapter_hh
#define azure_storage_adapter_hh
#include "PathUtils.h"
#include "FileDescriptor.h"
#include <map>
#include <string>
#include "was/storage_account.h"
#include "was/blob.h"
#include "AzureStorageConfig.h"

class AzureStorageAdapter
{
private:
  AzureStorageConfig *azureStorageConfig;

public:
  AzureStorageAdapter(AzureStorageConfig *config)
  {
    this->azureStorageConfig = config;
    // utility::string_t storage_connection_string(_XPLATSTR("DefaultEndpointsProtocol=https;AccountName=myaccountname;AccountKey=myaccountkey"));
    // azure::storage::cloud_storage_account storage_account = azure::storage::cloud_storage_account::parse(storage_connection_string);

    // // Create a blob container
    // azure::storage::cloud_blob_client blob_client = storage_account.create_cloud_blob_client();
    //azure::storage::cloud_blob_container container = blob_client.get_container_reference(_XPLATSTR("my-sample-container"));
  }
  void getAttr(const char *path, struct stat *statbuf)
  {
    
  }
};

#endif //azure_storage_adapter_hh