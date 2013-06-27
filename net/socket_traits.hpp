#ifndef SOCKET_TRAITS_HPP_
#define SOCKET_TRAITS_HPP_

#include "osi_layer.hpp"
#include <type_traits>

template<typename SOCKET>
struct socket_layers
{
    static const OsiLayer min = SOCKET::scMinLayer;
    static const OsiLayer max = SOCKET::scMaxLayer;

    static_assert(min <= max, "Corrupt layer ordering");
};

namespace pdu_tags {

struct pdu_tag {};
struct empty_pdu_tag : public pdu_tag {};

struct phy_tag : public pdu_tag {};
struct mk2_tag : public phy_tag {};

struct mac_tag : public pdu_tag {};
struct ethernet_tag : public mac_tag {};

} // namespace pdu_tags

template<typename SOCKET, OsiLayer LAYER>
struct socket_layer_pdu
{
    typedef pdu_tags::empty_pdu_tag tag;
};

template<OsiLayer LAYER, typename TAG, class SOCKET>
bool constexpr pdu_match(const SOCKET&)
{
    return std::is_same<TAG, typename socket_layer_pdu<SOCKET, LAYER>::tag>::value;
}

#endif // SOCKET_TRAITS_HPP_
