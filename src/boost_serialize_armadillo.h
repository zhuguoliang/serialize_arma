#ifndef BOOST_SERIALIZE_ARMADILLO_H_
#define BOOST_SERIALIZE_ARMADILLO_H_
// code to serialize Armadillo vectors / matrices / cubes with Boost
#include <armadillo>
#include <sstream>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wshadow"
#include "boost/serialization/split_free.hpp"
#pragma GCC diagnostic pop

namespace boost {
namespace serialization {
// Row
template <class Archive, class T>
inline void save(Archive &ar, const arma::Row<T> &vec,
                 const uint32_t /*version*/) {
  std::ostringstream outStream;
  vec.save(outStream, arma::arma_binary);
  std::string outString = outStream.str();
  ar << outString;
}

template <class Archive, class T>
inline void load(Archive &ar, arma::Row<T> &vec, const uint32_t /*version*/) {
  std::string inString;
  ar >> inString;
  std::istringstream inStream(inString);
  vec.load(inStream, arma::arma_binary);
}

template <class Archive, class T>
inline void serialize(Archive &ar, arma::Row<T> &vec,
                      const uint32_t file_version) {
  boost::serialization::split_free(ar, vec, file_version);
}

// Vectors
//
template <class Archive, class T>
inline void save(Archive &ar, const arma::Col<T> &vec,
                 const uint32_t /*version*/) {
  std::ostringstream outStream;
  vec.save(outStream, arma::arma_binary);
  std::string outString = outStream.str();
  ar << outString;
}

template <class Archive, class T>
inline void load(Archive &ar, arma::Col<T> &vec, const uint32_t /*version*/) {
  std::string inString;
  ar >> inString;
  std::istringstream inStream(inString);
  vec.load(inStream, arma::arma_binary);
}

template <class Archive, class T>
inline void serialize(Archive &ar, arma::Col<T> &vec,
                      const uint32_t file_version) {
  boost::serialization::split_free(ar, vec, file_version);
}

// Matrices

template <class Archive, class T>
inline void save(Archive &ar, const arma::Mat<T> &mat,
                 const uint32_t /*version*/) {
  std::ostringstream outStream;
  mat.save(outStream, arma::arma_binary);
  std::string outString = outStream.str();
  ar << outString;
}

template <class Archive, class T>
inline void load(Archive &ar, arma::Mat<T> &mat, const uint32_t /*version*/) {
  std::string inString;
  ar >> inString;
  std::istringstream inStream(inString);
  mat.load(inStream, arma::arma_binary);
}

template <class Archive, class T>
inline void serialize(Archive &ar, arma::Mat<T> &mat,
                      const uint32_t file_version) {
  boost::serialization::split_free(ar, mat, file_version);
}

// Cubes

template <class Archive, class T>
inline void save(Archive &ar, const arma::Cube<T> &cube,
                 const uint32_t /*version*/) {
  std::ostringstream outStream;
  cube.save(outStream, arma::arma_binary);
  std::string outString = outStream.str();
  ar << outString;
}

template <class Archive, class T>
inline void load(Archive &ar, arma::Cube<T> &cube, const uint32_t /*version*/) {
  std::string inString;
  ar >> inString;
  std::istringstream inStream(inString);
  cube.load(inStream, arma::arma_binary);
}

template <class Archive, class T>
inline void serialize(Archive &ar, arma::Cube<T> &cube,
                      const uint32_t file_version) {
  boost::serialization::split_free(ar, cube, file_version);
}

} // namespace serialization
} // namespace boost

#endif /* BOOST_SERIALIZE_ARMADILLO_H_ */
