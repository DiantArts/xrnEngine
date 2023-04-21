#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::Vector3(
    Vector3::Type value
)
    : ::xrn::engine::component::detail::BasicType<::glm::vec3, T, hasChangedFlag>{ ::std::move(value) }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Setters getters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::set(
    const float value
) -> Vector3::ParentType&
{
    m_value = ::glm::vec3{ value, value, value };

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::set(
    const float valueX
    , const float valueY
    , const float valueZ
) -> Vector3::ParentType&
{
    m_value = ::glm::vec3{ valueX, valueY, valueZ };

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setXY(
    const float valueX
    , const float valueY
) -> Vector3::ParentType&
{
    m_value.x = valueX;
    m_value.y = valueY;

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value.x); }) {
        parent.formatValue(m_value.x);
        parent.formatValue(m_value.y);
    } else if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setXZ(
    const float valueX
    , const float valueZ
) -> Vector3::ParentType&
{
    m_value.x = valueX;
    m_value.z = valueZ;

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value.x); }) {
        parent.formatValue(m_value.x);
        parent.formatValue(m_value.z);
    } else if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::setYZ(
    const float valueY
    , const float valueZ
) -> Vector3::ParentType&
{
    m_value.y = valueY;
    m_value.z = valueZ;

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value.y); }) {
        parent.formatValue(m_value.y);
        parent.formatValue(m_value.z);
    } else if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getX() const
    -> float
{
    return m_value.x;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getY() const
    -> float
{
    return m_value.y;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getZ() const
    -> float
{
    return m_value.z;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getXY() const
    -> ::glm::vec2
{
    return ::glm::vec2{ m_value.x, m_value.y };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getXZ() const
    -> ::glm::vec2
{
    return ::glm::vec2{ m_value.x, m_value.z };
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::getYZ() const
    -> ::glm::vec2
{
    return ::glm::vec2{ m_value.y, m_value.z };
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Comparisons
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator<=>(
    const float rhs
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ m_value.x <=> rhs }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_value.y <=> rhs }; cmp != 0) {
        return cmp;
    }
    return this->m_value.z <=> rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator<=>(
    const Vector3::ParentType& rhs
) const
    -> ::std::partial_ordering
{
    if (auto cmp{ m_value.x <=> rhs.m_value.x }; cmp != 0) {
        return cmp;
    }
    if (auto cmp{ m_value.y <=> rhs.m_value.y }; cmp != 0) {
        return cmp;
    }
    return this->m_value.z <=> rhs.m_value.z;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator=(
    const float rhs
) -> Vector3::ParentType&
{
    this->set(rhs);

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator+(
    const float rhs
) const -> ::glm::vec3
{
    return m_value + rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator+=(
    const float rhs
) -> Vector3::ParentType&
{
    m_value += rhs;

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator-(
    const float rhs
) const -> ::glm::vec3
{
    return m_value - rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator-=(
    const float rhs
) -> Vector3::ParentType&
{
    m_value -= rhs;

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator*(
    const float rhs
) const -> ::glm::vec3
{
    return m_value * rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator*=(
    const float rhs
) -> Vector3::ParentType&
{
    m_value *= rhs;

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator/(
    const float rhs
) const -> ::glm::vec3
{
    return m_value / rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::Vector3<T, hasChangedFlag>::operator/=(
    const float rhs
) -> Vector3::ParentType&
{
    m_value /= rhs;

    auto& parent{ static_cast<Vector3::ParentType&>(*this) };

    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }

    // format the value if method is provided
    if constexpr (requires { parent.formatValue(m_value); }) {
        parent.formatValue(m_value);
    }

    return parent;
}
