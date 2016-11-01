#include "AzureStorageFS.h"
#include "PathUtils.h"
#include <syslog.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
AzureStorageFSEnv *AzureStorageFS::asEnv = NULL;
const char *AzureStorageFS::_root = NULL;
AzureStorageAdapter *AzureStorageFS::asAdapter = NULL;

void AzureStorageFS::AbsPath(char dest[PATH_MAX], const char *path)
{
    strcpy(dest, _root);
    strncat(dest, path, PATH_MAX);
}

void AzureStorageFS::set_rootdir(const char *path)
{
    _root = path;
    syslog(LOG_INFO, "set_rootdir\n");
}

int AzureStorageFS::AzureStorageFS::wrap_getattr(const char *path, struct stat *statbuf)
{
    syslog(LOG_INFO, "AzureStorageFS::wrap_getattr %s\n", path);
    syslog(LOG_INFO, "statbuf==null? %d\n", (statbuf == NULL));

    // '/'
    // '/abo'
    // '/abc/efg'
    FilePath *filePath = PathUtils::parse(path);
    if (NULL != filePath)
    {
        if (NULL == filePath->fileName)
        {
            syslog(LOG_INFO, "directory\n");
            statbuf->st_mode = S_IFDIR;
            statbuf->st_size = 0;
        }
        else
        {
            syslog(LOG_INFO, "file\n");
            statbuf->st_mode= S_IFREG | 0644;
            statbuf->st_uid = getuid();
            statbuf->st_size = asAdapter->getSize(filePath);
        }
        delete filePath;
        filePath = NULL;
    }
    else
    {
        //TODO error handling.
    }
    return 0;
}

int AzureStorageFS::wrap_readlink(const char *path, char *link, size_t size)
{
    //return ExampleFS::Instance()->Readlink(path, link, size);
    syslog(LOG_INFO, "AzureStorageFS::wrap_readlink\n");
    return 0;
}

int AzureStorageFS::wrap_mknod(const char *path, mode_t mode, dev_t dev)
{
    //return ExampleFS::Instance()->Mknod(path, mode, dev);
    syslog(LOG_INFO, "AzureStorageFS::wrap_mknod\n");
    return 0;
}

int AzureStorageFS::wrap_mkdir(const char *path, mode_t mode)
{
    //return ExampleFS::Instance()->Mkdir(path, mode);
    syslog(LOG_INFO, "AzureStorageFS::wrap_mkdir\n");
    return 0;
}
int AzureStorageFS::wrap_unlink(const char *path)
{
    //return ExampleFS::Instance()->Unlink(path);
    syslog(LOG_INFO, "AzureStorageFS::wrap_unlink\n");
    return 0;
}
int AzureStorageFS::wrap_rmdir(const char *path)
{
    //return ExampleFS::Instance()->Rmdir(path);
    syslog(LOG_INFO, "AzureStorageFS::wrap_rmdir\n");
    return 0;
}
int AzureStorageFS::wrap_symlink(const char *path, const char *link)
{
    //return ExampleFS::Instance()->Symlink(path, link);
    syslog(LOG_INFO, "AzureStorageFS::wrap_symlink\n");
    return 0;
}
int AzureStorageFS::wrap_rename(const char *path, const char *newpath)
{
    //return ExampleFS::Instance()->Rename(path, newpath);
    syslog(LOG_INFO, "AzureStorageFS::wrap_rename\n");
    return 0;
}
int AzureStorageFS::wrap_link(const char *path, const char *newpath)
{
    //return ExampleFS::Instance()->Link(path, newpath);
    syslog(LOG_INFO, "AzureStorageFS::wrap_link\n");
    return 0;
}
int AzureStorageFS::wrap_chmod(const char *path, mode_t mode)
{
    //return ExampleFS::Instance()->Chmod(path, mode);
    syslog(LOG_INFO, "AzureStorageFS::wrap_chmod\n");
    return 0;
}
int AzureStorageFS::wrap_chown(const char *path, uid_t uid, gid_t gid)
{
    //return ExampleFS::Instance()->Chown(path, uid, gid);
    syslog(LOG_INFO, "AzureStorageFS::wrap_chown\n");
    return 0;
}
int AzureStorageFS::wrap_truncate(const char *path, off_t newSize)
{
    //return ExampleFS::Instance()->Truncate(path, newSize);
    syslog(LOG_INFO, "AzureStorageFS::wrap_truncate\n");
    return 0;
}
int AzureStorageFS::wrap_utime(const char *path, struct utimbuf *ubuf)
{
    //return ExampleFS::Instance()->Utime(path, ubuf);
    syslog(LOG_INFO, "AzureStorageFS::wrap_utime\n");
    return 0;
}
int AzureStorageFS::wrap_open(const char *path, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Open(path, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_open\n");
    //fileInfo->fh = asEnv->generateFD(path);

    return fileInfo->fh;
}
int AzureStorageFS::wrap_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Read(path, buf, size, offset, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_read\n");
    return 0;
}
int AzureStorageFS::wrap_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Write(path, buf, size, offset, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_write\n");
    return 0;
}
int AzureStorageFS::wrap_statfs(const char *path, struct statvfs *statInfo)
{
    //return ExampleFS::Instance()->Statfs(path, statInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_statfs\n");
    return 0;
}
int AzureStorageFS::wrap_flush(const char *path, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Flush(path, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_flush\n");
    return 0;
}
int AzureStorageFS::wrap_release(const char *path, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Release(path, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_release\n");
    return 0;
}
int AzureStorageFS::wrap_fsync(const char *path, int datasync, struct fuse_file_info *fi)
{
    //return ExampleFS::Instance()->Fsync(path, datasync, fi);
    syslog(LOG_INFO, "AzureStorageFS::wrap_fsync\n");
    return 0;
}
int AzureStorageFS::wrap_setxattr(const char *path, const char *name, const char *value, size_t size, int flags)
{
    //return ExampleFS::Instance()->Setxattr(path, name, value, size, flags);
    syslog(LOG_INFO, "AzureStorageFS::wrap_setxattr\n");
    return 0;
}
int AzureStorageFS::wrap_getxattr(const char *path, const char *name, char *value, size_t size)
{
    //return ExampleFS::Instance()->Getxattr(path, name, value, size);
    syslog(LOG_INFO, "AzureStorageFS::wrap_getxattr\n");
    return 0;
}
int AzureStorageFS::wrap_listxattr(const char *path, char *list, size_t size)
{
    //return ExampleFS::Instance()->Listxattr(path, list, size);
    syslog(LOG_INFO, "AzureStorageFS::wrap_listxattr\n");
    return 0;
}
int AzureStorageFS::wrap_removexattr(const char *path, const char *name)
{
    //return ExampleFS::Instance()->Removexattr(path, name);
    syslog(LOG_INFO, "AzureStorageFS::wrap_removexattr\n");
    return 0;
}
int AzureStorageFS::wrap_opendir(const char *path, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Opendir(path, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_opendir\n");
    return 0;
}
int AzureStorageFS::wrap_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Readdir(path, buf, filler, offset, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_readdir\n");
    return 0;
}
int AzureStorageFS::wrap_releasedir(const char *path, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Releasedir(path, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_releasedir\n");
    return 0;
}
int AzureStorageFS::wrap_fsyncdir(const char *path, int datasync, struct fuse_file_info *fileInfo)
{
    //return ExampleFS::Instance()->Fsyncdir(path, datasync, fileInfo);
    syslog(LOG_INFO, "AzureStorageFS::wrap_fsyncdir\n");
    return 0;
}
void *AzureStorageFS::wrap_init(struct fuse_conn_info *conn)
{
    //return ExampleFS::Instance()->Init(conn);
    syslog(LOG_INFO, "AzureStorageFS::wrap_init\n");
    return 0;
}
