///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Engine/System/UpdateTransform3d.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Basic
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::xrn::engine::system::UpdateTransform3d::operator()(
    ::xrn::engine::vulkan::FrameInfo& frameInfo [[ maybe_unused ]]
    , ::xrn::engine::component::Transform3d& transform
    , ::xrn::OptRef<::xrn::engine::component::Position> position
    , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
    , ::xrn::OptRef<::xrn::engine::component::Scale> scale
    , ::xrn::OptRef<::xrn::engine::component::Direction> direction
) const
{
    if (position) {
        if (rotation) {
            if (scale) {
                if (position->isChanged() || rotation->isChanged() || scale->isChanged()) {
                    transform.updateMatrix(position, rotation, scale);
                    transform.updateNormalMatrix(rotation, scale);
                }
                scale->resetChangedFlag();
                rotation->resetChangedFlag();
            } else if (position->isChanged() || rotation->isChanged()) {
                transform.updateMatrix(position, rotation);
                transform.updateNormalMatrix(rotation);
                rotation->resetChangedFlag();
            }
        // } else if (direction) {
            // ::glm::mat4 rotationMatrix = ::glm::lookAt(glm::vec3(0.0f), **direction, glm::vec3(0.0f, 1.0f, 0.0f));
            // ::xrn::engine::component::Rotation rotation2{
                // ::glm::degrees(glm::eulerAngles(glm::quat(rotationMatrix)))
            // };
            // rotation2.addY(90);
            // if (scale) {
                // if (position->isChanged() || direction->isChanged() || scale->isChanged()) {
                    // transform.updateMatrix(position, rotation2, scale);
                    // transform.updateNormalMatrix(rotation2, scale);
                // }
                // scale->resetChangedFlag();
                // direction->resetChangedFlag();
            // } else if (position->isChanged() || direction->isChanged()) {
                // transform.updateMatrix(position, rotation2);
                // transform.updateNormalMatrix(rotation2);
                // direction->resetChangedFlag();
            // }
        } else {
            if (scale) {
                if (position->isChanged() || scale->isChanged()) {
                    transform.updateMatrix(position);
                    transform.updateMatrix(position, scale);
                    transform.updateNormalMatrix(scale);
                    scale->resetChangedFlag();
                }
            } else if (position->isChanged()) {
                transform.updateMatrix(position);
            }
        }
        position->resetChangedFlag();
    }
}
