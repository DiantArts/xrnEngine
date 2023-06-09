#pragma once

#include <xrn/Engine/Vulkan/FrameInfo.hpp>
#include <xrn/Engine/Component/Transform3d.hpp>
#include <xrn/Engine/Component/Position.hpp>
#include <xrn/Engine/Component/Rotation.hpp>
#include <xrn/Engine/Component/Scale.hpp>
#include <xrn/Engine/Component/Direction.hpp>

namespace xrn::engine::system {

///////////////////////////////////////////////////////////////////////////
/// \brief No clue what it does xD
/// \ingroup vulkan
///
/// \include UpdateTransform3d.hpp <UpdateTransform3d.hpp>
///
///////////////////////////////////////////////////////////////////////////
class UpdateTransform3d {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Basic
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void operator()(
        ::xrn::engine::component::Transform3d& transform
        , ::xrn::OptRef<::xrn::engine::component::Position> position
        , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
        , ::xrn::OptRef<::xrn::engine::component::Scale> scale
        , ::xrn::OptRef<::xrn::engine::component::Direction> direction
    ) const;

};

} // namespace xrn::engine::system
