#include <pch.hpp>
#include <xrn/Engine/Component/Position.hpp>
#include <xrn/Engine/Component/Control.hpp>
#include <xrn/Engine/Component/Velocity.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position()
    : ::xrn::engine::component::detail::Vector3<Position>{ ::glm::vec3{ 0.f, 0.f, 0.f } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    const float value
)
    : ::xrn::engine::component::detail::Vector3<Position>{ ::glm::vec3{ value, value, value } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    ::glm::vec3 value
)
    : ::xrn::engine::component::detail::Vector3<Position>{ ::std::move(value) }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Position::Position(
    const float valueX
    , const float valueY
    , const float valueZ
)
    : ::xrn::engine::component::detail::Vector3<Position>{
        ::glm::vec3{ valueX, valueY, valueZ }
    }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Update
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Position::update(
    const ::xrn::Time deltaTime
    , const ::xrn::engine::component::Velocity& velocity
) -> Position&
{
    if (*velocity == ::glm::vec3{ 0.f }) {
        return *this;
    }

    this->add(velocity * deltaTime.getAsSeconds());
    return *this;
}
