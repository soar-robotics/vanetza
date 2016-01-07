#ifndef SIGNATURE_HPP_ZWPLNDVE
#define SIGNATURE_HPP_ZWPLNDVE

#include <vanetza/security/ecc_point.hpp>
#include <vanetza/security/public_key.hpp>
#include <vanetza/security/serialization.hpp>
#include <boost/variant/variant.hpp>

namespace vanetza
{
namespace security
{

struct EcdsaSignature
{
    EccPoint R;
    ByteBuffer s;
};

typedef boost::variant<EcdsaSignature> Signature;

/**
 * Determines PublcKeyAlgorithm to a given Signature
 * \param Signature
 * \return PublicKeyAlgorithm
 */
PublicKeyAlgorithm get_type(const Signature&);

/**
 * Calculates size of a Signature
 * \param Sigtnature
 * \return size_t containing the number of octets needed to serialize the Sigtnature
 */
size_t get_size(const EcdsaSignature&);
size_t get_size(const Signature&);

/**
 * Serializes a Signature into a binary archive
 * \param achive to serialize in
 * \param PublicKey to serialize
 */
void serialize(OutputArchive&, const Signature&);
void serialize(OutputArchive&, const EcdsaSignature&);

/**
 * Deserializes an object from a binary archive
 * \param archive with a serialized object at the beginning
 * \param object to deserialize
 * \return size of the deserialized object
 */
size_t deserialize(InputArchive&, EcdsaSignature&, const PublicKeyAlgorithm&);
size_t deserialize(InputArchive&, Signature&);

/**
 * Serialize the parts of a Signature
 * to return the ByteBuffer representation
 * \param Signature to be converted
 * \return ByteBuffer
 */
ByteBuffer extract_signature_buffer(const Signature& sig);

}
}
#endif /* SIGNATURE_HPP_ZWPLNDVE */
