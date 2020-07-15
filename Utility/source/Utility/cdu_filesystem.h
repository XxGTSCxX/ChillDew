#pragma once

#include "cdu_core.h"
#include "cdu_singleton.inl"
#include <unordered_map> // std::unordered_map
#include <filesystem>    // std::filesystem::path

namespace chilldew::utility
{

    struct filesystem : public singleton<filesystem>
    {
        // List of built in mounts
        struct mounts
        {
            static constexpr cd::string_view user   = CD_STRING("user"  );
            static constexpr cd::string_view assets = CD_STRING("assets");
        };

        struct path
        {
            cd::string            m_mount;
            std::filesystem::path m_relative_path;

            path(cd::string_view const& mount, std::filesystem::path const& relative_path);

            path& operator/=(cd::string_view const& append);
            path  operator/ (cd::string_view const& append) const;
        };

        struct file : public cd::fstream
        {
            enum class access : std::uint8_t
            {
                  read       = 0b01
                , write      = 0b10
                , read_write = 0b11

                , all = read_write
            };

            file(std::filesystem::path const& filepath, access file_access, bool is_binary);
            ~file();
        };

        static std::filesystem::path working_directory();
        static std::filesystem::path appdata_directory();

        filesystem();

        // Returns true if mount was successfully added
        bool add_mount(cd::string_view const& mount, std::filesystem::path const& mount_path);

        file create_file(path filepath, file::access file_access = file::access::read_write, bool is_binary = false) const;

        std::filesystem::path convert_path(path       const& custom_path) const;
        std::filesystem::path get_path    (cd::string const& mount      ) const;

    private:

        using mount_list_t = std::unordered_map<cd::string, std::filesystem::path>;

        mount_list_t m_mounts;
    };

}
