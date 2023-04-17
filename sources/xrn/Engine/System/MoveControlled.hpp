#pragma once

#include <xrn/Engine/Vulkan/FrameInfo.hpp>
#include <xrn/Engine/Component/Control.hpp>
#include <xrn/Engine/Component/Position.hpp>
#include <xrn/Engine/Component/Rotation.hpp>

namespace xrn::engine::system {

///////////////////////////////////////////////////////////////////////////
/// \brief No clue what it does xD
/// \ingroup vulkan
///
/// \include MoveControlled.hpp <MoveControlled.hpp>
///
///////////////////////////////////////////////////////////////////////////
class MoveControlled {

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
        ::xrn::engine::vulkan::FrameInfo& frameInfo
        , ::xrn::engine::component::Control& control
        , ::xrn::OptRef<::xrn::engine::component::Position> position
        , ::xrn::OptRef<::xrn::engine::component::Rotation> rotation
    ) const;

};

} // namespace xrn::engine::system
