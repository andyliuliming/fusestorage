#ifndef path_utils_hh
#define path_utils_hh
#include <string>
class FilePath
{
  public:
    std::string *directory;
    std::string *fileName;
    ~FilePath()
    {
        if (this->directory == NULL)
        {
            delete this->directory;
            this->directory = NULL;
        }
        if (this->fileName == NULL)
        {
            delete this->fileName;
            this->fileName = NULL;
        }
    }
};

class PathUtils
{
  public:
    PathUtils()
    {
    }
    static FilePath *parse(const char *path)
    {
        // if have more than one '/' then it's file, or it's a dir because 
        // aure storage only support one container and one path.
        // '/' is root path
        // '/abc' is a file
        // '/abc/def' is a file
        // '/abc/' is a directory
        std::string pathStr = path;
        std::size_t firstSlash = pathStr.find('/');
        std::size_t lastOfSlash = pathStr.find_last_of('/');
        if(firstSlash==lastOfSlash)
        {
            // folder???
        }
        return NULL;
    }
};

#endif //path_utils_hh