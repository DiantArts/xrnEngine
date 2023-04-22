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
    , typename U
    , bool hasChangedFlag
> ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::BasicType(
    const BasicType::Type value
)
    : m_value{ ::std::move(value) }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Rule of 5
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::~BasicType() = default;

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::BasicType(
    BasicType&&
) noexcept = default;;

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator=(
    BasicType&&
) noexcept
    -> BasicType& = default;;



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Setters getters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::set(
    const BasicType::Type value
) -> BasicType::ParentType&
{
    m_value = ::std::move(value);

    auto& parent{ static_cast<BasicType::ParentType&>(*this) };

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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::add(
    const BasicType::Type& value
) -> BasicType::ParentType&
{
    m_value += value;

    auto& parent{ static_cast<BasicType::ParentType&>(*this) };

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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::get() const
    -> const BasicType::Type&
{
    return m_value;
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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator<=>(
    const BasicType::Type& rhs
) const
    -> ::std::partial_ordering
{
    return this->m_value <=> rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator<=>(
    const BasicType& rhs
) const
    -> ::std::partial_ordering
{
    return this->m_value <=> rhs.m_value;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator=(
    const BasicType::Type& rhs
) -> BasicType::ParentType&
{
    this->set(rhs);

    auto& parent{ static_cast<BasicType::ParentType&>(*this) };

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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator+(
    const BasicType::Type& rhs
) const
-> BasicType::Type
{
    return m_value + rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator+=(
    const BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value += rhs;

    auto& parent{ static_cast<BasicType::ParentType&>(*this) };

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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator-(
    const BasicType::Type& rhs
) const
-> BasicType::Type
{
    return m_value - rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator-=(
    const BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value -= rhs;

    auto& parent{ static_cast<BasicType::ParentType&>(*this) };

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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator*(
    const BasicType::Type& rhs
) const
-> BasicType::Type
{
    return m_value * rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator*=(
    const BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value *= rhs;

    auto& parent{ static_cast<BasicType::ParentType&>(*this) };

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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator/(
    const BasicType::Type& rhs
) const
-> BasicType::Type
{
    return m_value / rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator/=(
    const BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value /= rhs;

    auto& parent{ static_cast<BasicType::ParentType&>(*this) };

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
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator*() const
    -> const BasicType::Type&
{
    return m_value;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> ::xrn::engine::component::detail::BasicType<T, U, true>::BasicType(
    BasicType::Type value
)
    : BasicType<T, U, false>{ ::std::move(value) }
    , m_isChanged{ true }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Changed flag
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> auto ::xrn::engine::component::detail::BasicType<T, U, true>::isChanged() const
    -> bool
{
    return m_isChanged;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> void ::xrn::engine::component::detail::BasicType<T, U, true>::setChangedFlag(
    bool value // = true
)
{
    m_isChanged = value;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> auto ::xrn::engine::component::detail::BasicType<T, U, true>::resetChangedFlag()
    -> BasicType::ParentType&
{
    m_isChanged = false;
    return static_cast<BasicType::ParentType&>(*this);
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Opposite way Comparisons
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool V
> auto operator+(
    const auto& lhs
    , const ::xrn::engine::component::detail::BasicType<T, U, V>& rhs
) -> decltype(lhs + rhs.get())
{
    return lhs + rhs.get();
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool V
> auto operator-(
    const auto& lhs
    , const ::xrn::engine::component::detail::BasicType<T, U, V>& rhs
) -> decltype(lhs - rhs.get())
{
    return lhs - rhs.get();
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool V
> auto operator*(
    const auto& lhs
    , const ::xrn::engine::component::detail::BasicType<T, U, V>& rhs
) -> decltype(lhs * rhs.get())
{
    return lhs * rhs.get();
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool V
> auto operator/(
    const auto& lhs
    , const ::xrn::engine::component::detail::BasicType<T, U, V>& rhs
) -> decltype(lhs / rhs.get())
{
    return lhs / rhs.get();
}
