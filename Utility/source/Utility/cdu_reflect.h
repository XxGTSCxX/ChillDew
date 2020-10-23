#pragma once

#include "cdu_reflector.h"

#define CDU_REFLECT_ENABLE template <typename value_t> friend struct cdu::reflection::blueprint;

#define CDU_REFLECT_BEGIN(object_t)                                              \
    typename <>                                                                  \
    struct cdu::reflection::blueprint<object_t>                                  \
    {                                                                            \
        using self_t = type;                                                     \
                                                                                 \
        cdu::type::id_t                     m_type_id = cdu::type::id<self_t>(); \
        cdu::vector<cdu::reflection::entry> m_entries;                           \
                                                                                 \
        blueprint()                                                              \
        {                                                                        \

#define CDU_REFLECT_VARIABLE(variable_name) \
            register_variable(&self_t::variable_name);

#define CDU_REFLECT_END(type)                                                                                                       \
        }                                                                                                                           \
    };                                                                                                                              \
                                                                                                                                    \
    template <>                                                                                                                     \
    static inline bool cdu::reflection::details::type_is_reflected<type> = cdu::reflection::reflector::get().register_type<type>();
