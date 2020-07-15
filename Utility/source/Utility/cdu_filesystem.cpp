#include "cdu_filesystem.h"
#include "cdu_flag.inl"
#include <functional> // std::hash
#include <cassert>    // assert
#include <Shlobj_core.h>

#ifdef _WIN32
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

namespace chilldew::utility
{

    namespace detail
    {
        inline int filemode_to_iosflag(filesystem::file::access file_access, bool is_binary)
        {
            cdu::flag<filesystem::file::access> flags { file_access };
            int                                 result{      0      };

            if (flags.is_on(filesystem::file::access::read))
                result |= std::ios_base::in;

            if (flags.is_on(filesystem::file::access::write))
                result |= std::ios_base::out;

            if (is_binary)
                result |= std::ios_base::binary;

            return result;
        }
    }

    filesystem::path::path(cd::string_view const& mount, std::filesystem::path const& relative_path)
    : m_mount        { mount         }
    , m_relative_path{ relative_path }
    {}

    filesystem::path& filesystem::path::operator/=(cd::string_view const& append)
    {
        m_relative_path /= append;
        return *this;
    }

    filesystem::path filesystem::path::operator/(cd::string_view const& append) const
    {
        return path{ *this } /= append;
    }

    filesystem::file::file(std::filesystem::path const& filepath, access file_access, bool is_binary)
    : cd::fstream{}
    {
        open(filepath, detail::filemode_to_iosflag(file_access, is_binary));
    }

    filesystem::file::~file()
    {
        if (is_open())
        {
            close();
        }
    }

    std::filesystem::path filesystem::working_directory()
    {
        char buffer[FILENAME_MAX] = {};
        (void)(GetCurrentDir(buffer, FILENAME_MAX));
        return buffer;
    }

    std::filesystem::path filesystem::appdata_directory()
    {
        char*       buffer = nullptr;
        std::size_t count  = 0;
        auto        result = _dupenv_s(&buffer, &count, "APPDATA");
        std::string directory;

        assert(result == 0 && buffer);

        directory = buffer;
        ::free(buffer);

        return directory;
    }

    filesystem::filesystem()
    {
        bool result;

        result = add_mount(mounts::user  , appdata_directory()               / "chilldew"); assert(result);
        result = add_mount(mounts::assets, working_directory().parent_path() / "assets"  ); assert(result);
    }

    bool filesystem::add_mount(cd::string_view const& mount, std::filesystem::path const& mount_path)
    {
        return m_mounts.emplace(mount, mount_path).second;
    }

    filesystem::file filesystem::create_file(path filepath, file::access file_access, bool is_binary) const
    {
        auto final_path = convert_path(filepath);

        if (!std::filesystem::exists(final_path.parent_path()))
        {
            std::filesystem::create_directories(final_path.parent_path());
        }

        return file{ final_path, file_access, is_binary };
    }

    std::filesystem::path filesystem::convert_path(path const& custom_path) const
    {
        std::filesystem::path result;
        auto                  itr = m_mounts.find(custom_path.m_mount);

        if (itr != m_mounts.end())
        {
            result  = itr->second;
            result /= custom_path.m_relative_path;
        }

        return result;
    }

    std::filesystem::path filesystem::get_path(cd::string const& mount) const
    {
        auto itr = m_mounts.find(mount);

        if (itr != m_mounts.end())
        {
            return itr->second;
        }

        return std::filesystem::path{};
    }

}
