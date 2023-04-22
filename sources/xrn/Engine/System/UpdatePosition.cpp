///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Engine/System/UpdatePosition.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Basic
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// void ::xrn::engine::system::UpdatePosition::operator()(
    // ::xrn::engine::vulkan::FrameInfo& frameInfo
    // , ::xrn::engine::component::Position& position
    // , ::xrn::OptRef<::xrn::engine::component::Control> control
    // , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
    // , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
    // , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
// ) const
// {
    // if (control) {
        // ::xrn::OptRef<const ::glm::vec3> direction;
        // if (rotation) {
            // rotation->updateDirection(control);
            // direction = rotation->getDirection();
        // } else {
            // direction = this->defaultDirection;
        // }

        // if (velocity) {
            // velocity->update(control);

            // TODO: acceleration with control not working
            // if (acceleration) {
                // velocity->apply(frameInfo.deltaTime, acceleration);
            // }

            // position.update(frameInfo.deltaTime, control, velocity, direction);
        // } else {
            // position.update(frameInfo.deltaTime, control, direction);
        // }
        // return;
    // }
    // if (velocity) {
        // ::xrn::OptRef<const ::glm::vec3> direction;
        // if (rotation) {
            // rotation->updateDirection();
            // direction = rotation->getDirection();
        // } else {
            // direction = this->defaultDirection;
        // }

        // if (acceleration) {
            // velocity->apply(frameInfo.deltaTime, acceleration);
        // }

        // position.update(frameInfo.deltaTime, velocity, direction);
    // }
// }

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::system::UpdatePosition::operator()(
    ::xrn::engine::vulkan::FrameInfo& frameInfo
    , ::xrn::engine::component::Position& position
    , ::xrn::engine::component::Control& control
    , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
    , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
    , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
    , ::xrn::OptRef<const ::xrn::engine::component::Mass> mass
) const
{
    XRN_THROW("Control not supported anymore")
    // ::xrn::OptRef<const ::glm::vec3> direction;
    // if (rotation) {
        // rotation->updateDirection(control);
        // direction = rotation->getDirection();
    // } else {
        // direction = this->defaultDirection;
    // }

    // this->updatePosition(frameInfo, position, velocity, direction, acceleration, mass);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::system::UpdatePosition::operator()(
    ::xrn::engine::vulkan::FrameInfo& frameInfo
    , ::xrn::engine::component::Position& position
    , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
    , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
    , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
    , ::xrn::OptRef<const ::xrn::engine::component::Mass> mass
) const
{
    ::xrn::OptRef<const ::glm::vec3> direction;
    if (rotation) {
        rotation->updateDirection();
        direction = rotation->getDirection();
    } else {
        direction = this->defaultDirection;
    }

    this->updatePosition(frameInfo, position, direction, velocity, acceleration, mass);
}

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::system::UpdatePosition::updatePosition(
    ::xrn::engine::vulkan::FrameInfo& frameInfo
    , ::xrn::engine::component::Position& position
    , const ::glm::vec3& direction
    , ::xrn::OptRef<::xrn::engine::component::Velocity> velocity
    , ::xrn::OptRef<::xrn::engine::component::Acceleration> acceleration
    , ::xrn::OptRef<const ::xrn::engine::component::Mass> mass
) const
{
    if (velocity) {
        // velocity->updateDirection(direction);
        if (acceleration) {
            if (mass && mass->get() != 0.f) {
                acceleration->addForce(mass->get() * m_gravity);
                velocity->applyAcceleration(frameInfo.deltaTime, acceleration, mass);
            } else {
                velocity->applyAcceleration(frameInfo.deltaTime, acceleration);
            }
        }
        velocity->setLength(velocity->getMaximumSpeed());
        position.update(frameInfo.deltaTime, velocity);
    }
}
