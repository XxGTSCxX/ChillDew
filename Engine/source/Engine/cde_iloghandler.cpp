#include "CD_pch.h"
#include "cde_iloghandler.h"

namespace chilldew::engine
{

    iloghandler::iloghandler(cd::string_view const& name)
    : m_name{ name }
    {}

    cd::string const& iloghandler::get_name() const
    {
        return m_name;
    }

    void iloghandler::set_name(cd::string_view const& name)
    {
        m_name = name;
    }

}
