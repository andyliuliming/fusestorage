#ifndef azure_storage_adapter_hh
#define azure_storage_adapter_hh
#include "PathUtils.h"
#include "FileDescriptor.h"
#include <map>
#include <string>
#include <syslog.h>
#include "was/storage_account.h"
#include "was/blob.h"
#include "AzureStorageConfig.h"

class AzureStorageAdapter
{
private:
  AzureStorageConfig *azureStorageConfig;
  azure::storage::cloud_storage_account *storage_account;
  azure::storage::cloud_blob_client *blob_client;

public:
  AzureStorageAdapter(AzureStorageConfig *config)
  {
    this->azureStorageConfig = config;
    std::string connectionStr = std::string("DefaultEndpointsProtocol=http;EndpointSuffix=core.chinacloudapi.cn;AccountName=") + config->storageAccountName + ";AccountKey=" + config->storageAccountKey;
    utility::string_t storage_connection_string(_XPLATSTR(connectionStr));
    this->storage_account = new azure::storage::cloud_storage_account(azure::storage::cloud_storage_account::parse(storage_connection_string));
    this->blob_client = new azure::storage::cloud_blob_client(this->storage_account->create_cloud_blob_client());
  }
  long getSize(FilePath *filePath);
  ~AzureStorageAdapter()
  {
  }
};

#endif //azure_storage_adapter_hh