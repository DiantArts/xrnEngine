#pragma once

///////////////////////////////////////////////////////////////////////////
// Public Headers
///////////////////////////////////////////////////////////////////////////

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/hash.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/geometric.hpp>

#include <stb/stb_image.h>

#include <entt/entt.hpp>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define XRN_USE_VALIDATION_LAYERS

#include <SFML/Audio.hpp>

inline auto operator<<(
    ::std::ostream& os
    , const ::glm::vec2& vec
) -> ::std::ostream&
{
    os << '[' << vec.x << ", " << vec.y << ']';
    return os;
}

template <
    typename T
> auto operator<<(
    ::xrn::network::Message<T>& message
    , const ::glm::vec2& vec
) -> ::xrn::network::Message<T>&
{
    message << vec.x << vec.y;
    return message;
}

template <
    typename T
> auto operator>>(
    ::xrn::network::Message<T>& message
    , ::glm::vec2& vec
) -> ::xrn::network::Message<T>&
{
    message >> vec.x >> vec.y;
    return message;
}

inline auto operator<<(
    ::std::ostream& os
    , const ::glm::vec3& vec
) -> ::std::ostream&
{
    os << '[' << vec.x << ", " << vec.y << ", " << vec.z << ']';
    return os;
}

template <> struct fmt::formatter<::glm::vec3> {
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()){ return ctx.begin(); }
    template <typename FormatContext> auto format(const ::glm::vec3& vec, FormatContext& ctx) -> decltype(ctx.out()){
        return format_to( ctx.out(), "::glm::vec3{}{}, {}, {}{}", '{', vec.x, vec.y, vec.z, '}');
    }
};

template <> struct fmt::formatter<::glm::vec2> {
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()){ return ctx.begin(); }
    template <typename FormatContext> auto format(const ::glm::vec2& vec, FormatContext& ctx) -> decltype(ctx.out()){
        return format_to( ctx.out(), "::glm::vec2{}{}, {}{}", '{', vec.x, vec.y, '}');
    }
};

template <
    typename T
> auto operator<<(
    ::xrn::network::Message<T>& message
    , const ::glm::vec3& vec
) -> ::xrn::network::Message<T>&
{
    message << vec.x << vec.y << vec.z;
    return message;
}

template <
    typename T
> auto operator>>(
    ::xrn::network::Message<T>& message
    , ::glm::vec3& vec
) -> ::xrn::network::Message<T>&
{
    message >> vec.x >> vec.y >> vec.z;
    return message;
}



///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////

#include <xrn/Engine/AScene.hpp>
#include <xrn/Engine/Components.hpp>
#include <xrn/Engine/Configuration.hpp>
#include <xrn/Engine/Vulkan/errorToString.hpp>




///////////////////////////////////////////////////////////////////////////
/// \defgroup engine Engine module
///
///////////////////////////////////////////////////////////////////////////
