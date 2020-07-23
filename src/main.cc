#include "boost_serialize_armadillo.h"
#include <armadillo>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/tmpdir.hpp>
#include <fstream>
#include <iostream>

void test_rowvec() {

  ////////////////////////////////////////
  arma::rowvec r1(5);
  r1.fill(123.0);
  r1.print("r1:");

  std::ofstream outputStream;
  outputStream.open("rbin.dat");
  boost::archive::binary_oarchive oa(outputStream);
  oa &r1;
  outputStream.close();

  arma::mat r2;
  std::ifstream inputStream;
  inputStream.open("rbin.dat", std::ifstream::in);
  boost::archive::binary_iarchive ia(inputStream);
  ia &r2;

  r2.print("r2:");
}

void test_mat() {
  arma::mat a = arma::randu(3, 4);
  a.print("a:");

  std::ofstream outputStream;
  outputStream.open("bin.dat");
  boost::archive::binary_oarchive oa(outputStream);
  oa &a;
  outputStream.close();

  arma::mat B;
  std::ifstream inputStream;
  inputStream.open("bin.dat", std::ifstream::in);
  boost::archive::binary_iarchive ia(inputStream);
  ia &B;

  B.print("B:");
}
int main() {
  ////////
  test_mat();
  test_rowvec();
  return 0;
}
