#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/projection.inl"
#include "glm/gtx/perpendicular.inl"
#include "ut_math.h"

namespace unit_tests
{

    using cdm_vec2 = cdm::vector<float, 2>;
    using glm_vec2 = glm::vec2;

    bool operator==(glm_vec2 const& lhs, cdm_vec2 const& rhs)
    {
        return lhs[0] == rhs[0] && lhs[1] == rhs[1];
    }

    bool operator==(cdm_vec2 const& lhs, glm_vec2 const& rhs)
    {
        return rhs == lhs;
    }

    template <>
    inline void math::test_vec<2>()
    {
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");
        cd::Debug::Get()->Log("// Vector 2D Tests"                                                              );
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");

        cd::stringstream stream;

        cdm_vec2 default_init{           };
        cdm_vec2 var_init    { 1,2       };
        cdm_vec2 fill_init   { 1         };
        cdm_vec2 copy_init   { fill_init };

        glm_vec2 glm_default_init{               };
        glm_vec2 glm_var_init    { 1,2           };
        glm_vec2 glm_fill_init   { 1             };
        glm_vec2 glm_copy_init   { glm_fill_init };

        copy_init = cdm_vec2{ 0,1 }; glm_copy_init = glm_vec2{ 0,1 };  cd::Debug::Get()->Log("operator=  : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init += var_init;       glm_copy_init += glm_var_init;    cd::Debug::Get()->Log("operator+= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init -= var_init;       glm_copy_init -= glm_var_init;    cd::Debug::Get()->Log("operator-= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init *= fill_init;      glm_copy_init *= glm_fill_init;   cd::Debug::Get()->Log("operator*= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init;       glm_copy_init /= glm_var_init;    cd::Debug::Get()->Log("operator/= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init *= var_init[1];    glm_copy_init *= glm_var_init[1]; cd::Debug::Get()->Log("operator*= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init[1];    glm_copy_init /= glm_var_init[1]; cd::Debug::Get()->Log("operator/= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");

        cd::Debug::Get()->Log("operator[] : {}",  copy_init[0]     == glm_copy_init[0] ? "Passed" : "Failed");
        cd::Debug::Get()->Log("data       : {}", *copy_init.data() == glm_copy_init[0] ? "Passed" : "Failed");
        cd::Debug::Get()->Log("size       : {}",  copy_init.size() == 2                ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator-  : {}", -copy_init        == -glm_copy_init   ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator== : {}",  copy_init        == copy_init        ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator!= : {}",  copy_init        != copy_init        ? "Failed" : "Passed");

        stream << copy_init;
        stream >> default_init;

        cd::Debug::Get()->Log("operator>> : {}", copy_init                                           == default_init                                                ? "Passed" : "Failed");
        cd::Debug::Get()->Log("dot        : {}", cdm::dot      (copy_init, var_init                ) == glm::dot      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("length     : {}", cdm::length   (copy_init                          ) == glm::length   (glm_copy_init                              ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("distance   : {}", cdm::distance (copy_init, var_init                ) == glm::distance (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("min        : {}", cdm::min      (copy_init, var_init                ) == glm::min      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("max        : {}", cdm::max      (copy_init, var_init                ) == glm::max      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("normalize  : {}", cdm::normalise(copy_init                          ) == glm::normalize(glm_copy_init                              ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("reflect    : {}", cdm::reflect  (copy_init, cdm::normalise(var_init)) == glm::reflect  (glm_copy_init, glm::normalize(glm_var_init)) ? "Passed" : "Failed");
    }

    using cdm_vec3 = cdm::vector<float, 3>;
    using glm_vec3 = glm::vec3;

    bool operator==(glm_vec3 const& lhs, cdm_vec3 const& rhs)
    {
        return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
    }

    bool operator==(cdm_vec3 const& lhs, glm_vec3 const& rhs)
    {
        return rhs == lhs;
    }

    template <>
    inline void math::test_vec<3>()
    {
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");
        cd::Debug::Get()->Log("// Vector 3D Tests"                                                              );
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");

        cd::stringstream stream;

        cdm_vec3 default_init{           };
        cdm_vec3 var_init    { 1,2,3     };
        cdm_vec3 fill_init   { 1         };
        cdm_vec3 copy_init   { fill_init };

        glm_vec3 glm_default_init{               };
        glm_vec3 glm_var_init    { 1,2,3         };
        glm_vec3 glm_fill_init   { 1             };
        glm_vec3 glm_copy_init   { glm_fill_init };

        copy_init  = cdm_vec3{ 0,1,0 }; glm_copy_init  = glm_vec3{ 0,1,0 }; cd::Debug::Get()->Log("operator=  : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init += var_init;          glm_copy_init += glm_var_init;      cd::Debug::Get()->Log("operator+= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init -= var_init;          glm_copy_init -= glm_var_init;      cd::Debug::Get()->Log("operator-= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init *= fill_init;         glm_copy_init *= glm_fill_init;     cd::Debug::Get()->Log("operator*= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init;          glm_copy_init /= glm_var_init;      cd::Debug::Get()->Log("operator/= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init *= var_init[1];       glm_copy_init *= glm_var_init[1];   cd::Debug::Get()->Log("operator*= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init[1];       glm_copy_init /= glm_var_init[1];   cd::Debug::Get()->Log("operator/= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");

        cd::Debug::Get()->Log("operator[] : {}",  copy_init[0]     == glm_copy_init[0] ? "Passed" : "Failed");
        cd::Debug::Get()->Log("data       : {}", *copy_init.data() == glm_copy_init[0] ? "Passed" : "Failed");
        cd::Debug::Get()->Log("size       : {}",  copy_init.size() == 3                ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator-  : {}", -copy_init        == -glm_copy_init   ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator== : {}",  copy_init        == copy_init        ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator!= : {}",  copy_init        != copy_init        ? "Failed" : "Passed");

        stream << copy_init;
        stream >> default_init;

        cd::Debug::Get()->Log("operator>> : {}", copy_init                                           == default_init                                                ? "Passed" : "Failed");
        cd::Debug::Get()->Log("dot        : {}", cdm::dot      (copy_init, var_init                ) == glm::dot      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("length     : {}", cdm::length   (copy_init                          ) == glm::length   (glm_copy_init                              ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("distance   : {}", cdm::distance (copy_init, var_init                ) == glm::distance (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("min        : {}", cdm::min      (copy_init, var_init                ) == glm::min      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("max        : {}", cdm::max      (copy_init, var_init                ) == glm::max      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("normalize  : {}", cdm::normalise(copy_init                          ) == glm::normalize(glm_copy_init                              ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("reflect    : {}", cdm::reflect  (copy_init, cdm::normalise(var_init)) == glm::reflect  (glm_copy_init, glm::normalize(glm_var_init)) ? "Passed" : "Failed");
    }

    using cdm_vec4 = cdm::vector<float, 4>;
    using glm_vec4 = glm::vec4;

    bool operator==(glm_vec4 const& lhs, cdm_vec4 const& rhs)
    {
        return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2] && lhs[3] == rhs[3];
    }

    bool operator==(cdm_vec4 const& lhs, glm_vec4 const& rhs)
    {
        return rhs == lhs;
    }

    template <>
    inline void math::test_vec<4>()
    {
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");
        cd::Debug::Get()->Log("// Vector 4D Tests"                                                              );
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");

        cd::stringstream stream;

        cdm_vec4 default_init{           };
        cdm_vec4 var_init    { 1,2,3,4   };
        cdm_vec4 fill_init   { 1         };
        cdm_vec4 copy_init   { fill_init };

        glm_vec4 glm_default_init{               };
        glm_vec4 glm_var_init    { 1,2,3,4       };
        glm_vec4 glm_fill_init   { 1             };
        glm_vec4 glm_copy_init   { glm_fill_init };

        copy_init  = cdm_vec4{ 0,1,0,1 }; glm_copy_init  = glm_vec4{ 0,1,0,1 }; cd::Debug::Get()->Log("operator=  : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init += var_init;            glm_copy_init += glm_var_init;        cd::Debug::Get()->Log("operator+= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init -= var_init;            glm_copy_init -= glm_var_init;        cd::Debug::Get()->Log("operator-= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init *= fill_init;           glm_copy_init *= glm_fill_init;       cd::Debug::Get()->Log("operator*= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init;            glm_copy_init /= glm_var_init;        cd::Debug::Get()->Log("operator/= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init *= var_init[1];         glm_copy_init *= glm_var_init[1];     cd::Debug::Get()->Log("operator*= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init[1];         glm_copy_init /= glm_var_init[1];     cd::Debug::Get()->Log("operator/= : {}", copy_init == glm_copy_init ? "Passed" : "Failed");

        cd::Debug::Get()->Log("operator[] : {}",  copy_init[0]     == glm_copy_init[0] ? "Passed" : "Failed");
        cd::Debug::Get()->Log("data       : {}", *copy_init.data() == glm_copy_init[0] ? "Passed" : "Failed");
        cd::Debug::Get()->Log("size       : {}",  copy_init.size() == 4                ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator-  : {}", -copy_init        == -glm_copy_init   ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator== : {}",  copy_init        == copy_init        ? "Passed" : "Failed");
        cd::Debug::Get()->Log("operator!= : {}",  copy_init        != copy_init        ? "Failed" : "Passed");

        stream << copy_init;
        stream >> default_init;

        cd::Debug::Get()->Log("operator>> : {}", copy_init                                           == default_init                                                ? "Passed" : "Failed");
        cd::Debug::Get()->Log("dot        : {}", cdm::dot      (copy_init, var_init                ) == glm::dot      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("length     : {}", cdm::length   (copy_init                          ) == glm::length   (glm_copy_init                              ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("distance   : {}", cdm::distance (copy_init, var_init                ) == glm::distance (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("min        : {}", cdm::min      (copy_init, var_init                ) == glm::min      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("max        : {}", cdm::max      (copy_init, var_init                ) == glm::max      (glm_copy_init, glm_var_init                ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("normalize  : {}", cdm::normalise(copy_init                          ) == glm::normalize(glm_copy_init                              ) ? "Passed" : "Failed");
        cd::Debug::Get()->Log("reflect    : {}", cdm::reflect  (copy_init, cdm::normalise(var_init)) == glm::reflect  (glm_copy_init, glm::normalize(glm_var_init)) ? "Passed" : "Failed");
    }

}
