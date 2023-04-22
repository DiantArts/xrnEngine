#pragma once

#include <xrn/Engine/Component/Detail/Vector3.hpp>

namespace xrn::engine::component {

class Vector3
    : public ::xrn::engine::component::detail::Vector3<Vector3, false>
{

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Static
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    EXPOSE_VECTOR3_METHODS(Vector3, false);



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit Vector3();

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit Vector3(
        float value
    );

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit Vector3(
        const ::glm::vec3& value
    );

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit Vector3(
        float valueX
        , float valueY
        , float valueZ
    );

};

} // namespace xrn::engine::component