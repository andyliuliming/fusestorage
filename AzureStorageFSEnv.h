#ifndef azure_storage_fs_env_hh
#define azure_storage_fs_env_hh
class AzureStorageFSEnv
{
  private:
  public:
    long fd;
    AzureStorageFSEnv()
    {
        this->fd = 0;
    }
    long generateFD()
    {
        return this->fd++;
    }
};

#endif //azure_storage_fs_env_hh