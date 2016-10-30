#include "AzureStorageFS.h"

void set_rootdir(const char *path) {
	//ExampleFS::Instance()->setRootDir(path);
}

int wrap_getattr(const char *path, struct stat *statbuf) {
	//return ExampleFS::Instance()->Getattr(path, statbuf);
    return 0;
}

int wrap_readlink(const char *path, char *link, size_t size) {
	//return ExampleFS::Instance()->Readlink(path, link, size);
    return 0;
}

int wrap_mknod(const char *path, mode_t mode, dev_t dev) {
	//return ExampleFS::Instance()->Mknod(path, mode, dev);
    return 0;
}

int wrap_mkdir(const char *path, mode_t mode) {
	//return ExampleFS::Instance()->Mkdir(path, mode);
    return 0;
}
int wrap_unlink(const char *path) {
	//return ExampleFS::Instance()->Unlink(path);
    return 0;
}
int wrap_rmdir(const char *path) {
	//return ExampleFS::Instance()->Rmdir(path);
    return 0;
}
int wrap_symlink(const char *path, const char *link) {
	//return ExampleFS::Instance()->Symlink(path, link);
    return 0;
}
int wrap_rename(const char *path, const char *newpath) {
	//return ExampleFS::Instance()->Rename(path, newpath);
    return 0;
}
int wrap_link(const char *path, const char *newpath) {
	//return ExampleFS::Instance()->Link(path, newpath);
    return 0;
}
int wrap_chmod(const char *path, mode_t mode) {
	//return ExampleFS::Instance()->Chmod(path, mode);
    return 0;
}
int wrap_chown(const char *path, uid_t uid, gid_t gid) {
	//return ExampleFS::Instance()->Chown(path, uid, gid);
    return 0;
}
int wrap_truncate(const char *path, off_t newSize) {
	//return ExampleFS::Instance()->Truncate(path, newSize);
    return 0;
}
int wrap_utime(const char *path, struct utimbuf *ubuf) {
	//return ExampleFS::Instance()->Utime(path, ubuf);
    return 0;
}
int wrap_open(const char *path, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Open(path, fileInfo);
    return 0;
}
int wrap_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Read(path, buf, size, offset, fileInfo);
    return 0;
}
int wrap_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Write(path, buf, size, offset, fileInfo);
    return 0;
}
int wrap_statfs(const char *path, struct statvfs *statInfo) {
	//return ExampleFS::Instance()->Statfs(path, statInfo);
    return 0;
}
int wrap_flush(const char *path, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Flush(path, fileInfo);
    return 0;
}
int wrap_release(const char *path, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Release(path, fileInfo);
    return 0;
}
int wrap_fsync(const char *path, int datasync, struct fuse_file_info *fi) {
	//return ExampleFS::Instance()->Fsync(path, datasync, fi);
    return 0;
}
int wrap_setxattr(const char *path, const char *name, const char *value, size_t size, int flags) {
	//return ExampleFS::Instance()->Setxattr(path, name, value, size, flags);
    return 0;
}
int wrap_getxattr(const char *path, const char *name, char *value, size_t size) {
	//return ExampleFS::Instance()->Getxattr(path, name, value, size);
    return 0;
}
int wrap_listxattr(const char *path, char *list, size_t size) {
	//return ExampleFS::Instance()->Listxattr(path, list, size);
    return 0;
}
int wrap_removexattr(const char *path, const char *name) {
	//return ExampleFS::Instance()->Removexattr(path, name);
    return 0;
}
int wrap_opendir(const char *path, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Opendir(path, fileInfo);
    return 0;
}
int wrap_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Readdir(path, buf, filler, offset, fileInfo);
    return 0;
}
int wrap_releasedir(const char *path, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Releasedir(path, fileInfo);
    return 0;
}
int wrap_fsyncdir(const char *path, int datasync, struct fuse_file_info *fileInfo) {
	//return ExampleFS::Instance()->Fsyncdir(path, datasync, fileInfo);
    return 0;
}
int wrap_init(struct fuse_conn_info *conn) {
	//return ExampleFS::Instance()->Init(conn);
    return 0;
}

