///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Engine/System/MoveControlled.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Basic
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::system::MoveControlled::operator()(
    ::xrn::engine::vulkan::FrameInfo& frameInfo
    , ::xrn::engine::component::Control& control
    , ::xrn::OptRef<::xrn::engine::component::Position> position
    , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
) const
{
    if (rotation) {
        rotation->updateDirection(control);
        if (position) {
            position->update(frameInfo.deltaTime, control, rotation->getDirection());
        }
    } else {
        if (position) {
            auto direction{
                ::glm::normalize(::glm::vec3(
                    ::glm::cos(::glm::radians(0.0f)) * ::glm::cos(::glm::radians(0.0f))
                    , ::glm::sin(::glm::radians(0.0f))
                    , ::glm::sin(::glm::radians(0.0f)) * ::glm::cos(::glm::radians(0.0f))
                ))
            };
            position->update(frameInfo.deltaTime, control, direction);
        }
    }
}
