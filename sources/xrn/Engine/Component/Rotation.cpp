#include <pch.hpp>
#include <xrn/Engine/Component/Rotation.hpp>
#include <xrn/Engine/Component/Control.hpp>
#include <xrn/Engine/Configuration.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructor
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Rotation::Rotation()
    : ::xrn::engine::component::detail::Vector3<Rotation>{ ::glm::vec3{ 0.f, 0.f, 0.f } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Rotation::Rotation(
    const float value
)
    : ::xrn::engine::component::detail::Vector3<Rotation>{ ::glm::vec3{ value, value, value } }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Rotation::Rotation(
    ::glm::vec3 value
)
    : ::xrn::engine::component::detail::Vector3<Rotation>{ ::std::move(value) }
{}

///////////////////////////////////////////////////////////////////////////
::xrn::engine::component::Rotation::Rotation(
    const float valueX
    , const float valueY
    , const float valueZ
)
    : ::xrn::engine::component::detail::Vector3<Rotation>{
        ::glm::vec3{ valueX, valueY, valueZ }
    }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Direction
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Rotation::updateDirection(
    ::xrn::engine::component::Control& control
)
{
    if (control.isRotated() || this->isChanged()) {
        auto newRotation{ this->get() + control.getRotation() };

        if (newRotation.y > ::xrn::engine::configuration.maxPitch) {
            newRotation.y = ::xrn::engine::configuration.maxPitch;
        } else if (newRotation.y < ::xrn::engine::configuration.minPitch) {
            newRotation.y = ::xrn::engine::configuration.minPitch;
        }

        this->set(::std::move(newRotation));
        m_direction = ::glm::normalize(::glm::vec3(
            ::glm::cos(::glm::radians(this->getX())) * ::glm::cos(::glm::radians(this->getY()))
            , ::glm::sin(::glm::radians(this->getY()))
            , ::glm::sin(::glm::radians(this->getX())) * ::glm::cos(::glm::radians(this->getY()))
        ));
        control.resetRotatedFlag();
        this->setChangedFlag(false);
    }
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Rotation::updateDirection()
{
    if (this->isChanged()) {
        m_direction = ::glm::normalize(::glm::vec3(
            ::glm::cos(::glm::radians(this->getX())) * ::glm::cos(::glm::radians(this->getY()))
            , ::glm::sin(::glm::radians(this->getY()))
            , ::glm::sin(::glm::radians(this->getX())) * ::glm::cos(::glm::radians(this->getY()))
        ));
        this->setChangedFlag(false);
    }
}

///////////////////////////////////////////////////////////////////////////
auto ::xrn::engine::component::Rotation::getDirection() const
    -> const ::glm::vec3&
{
    return m_direction;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Format value
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Rotation::formatValue(
    float& value
)
{
    while (value >= 360) {
        value -= 360;
    }
    while (value < 0) {
        value += 360;
    }
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::component::Rotation::formatValue(
    ::glm::vec3& value
)
{
    this->formatValue(value.x);
    this->formatValue(value.y);
    this->formatValue(value.z);
}
