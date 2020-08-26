#include "cdu_type.h"

namespace chilldew::utility
{

    bool type::is_base_of(id_t base_id, id_t derived_id)
    {
        if (base_id != type::invalid_id && derived_id != type::invalid_id)
        {
            if (base_id == derived_id)
                return true;

            auto&& itr = m_registered_types.find(derived_id);

            if (itr != m_registered_types.end())
            {
                for (auto&& parent_id : itr->second.m_base_types)
                {
                    if (type::is_base_of(base_id, parent_id))
                        return true;
                }
            }
        }

        return false;
    }

    bool type::is_registered(id_t type_id)
    {
        return m_registered_types.find(type_id) != m_registered_types.end();
    }

    bool type::is_registered(cd::string_view type_name)
    {
        return m_name_list.find(cd::string{ type_name }) != m_name_list.end();
    }

    cd::string_view type::name(id_t type_id)
    {
        auto itr = m_registered_types.find(type_id);

        if (itr != m_registered_types.end())
        {
            return itr->second.m_name;
        }

        return invalid_name;
    }

    type::id_t type::id(cd::string_view type_name)
    {
        auto itr = m_name_list.find(cd::string{ type_name });

        if (itr != m_name_list.end())
        {
            return itr->second;
        }

        return invalid_id;
    }

}
