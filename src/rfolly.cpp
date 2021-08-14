#include <Rcpp.h>
using namespace Rcpp;

#include "folly/small_vector.h"



static std::string malloc_stats_print_callback_string;
void malloc_stats_print_callback(void *, const char * data) {
  malloc_stats_print_callback_string = std::string(data);
}
// [[Rcpp::export(rng = false)]]
std::string rfolly_malloc_stats_print() {
#ifdef R_USE_JEMALLOC
  malloc_stats_print(malloc_stats_print_callback, nullptr, "");
  return malloc_stats_print_callback_string;
#endif
  return std::string("jemalloc not in use");
  Rprintf("malloc_stats_print done");
}

// [[Rcpp::export(rng = false)]]
void small_vector_test() {
  folly::small_vector<uint8_t, 12, uint32_t> x;
  if(sizeof(x) != 16) throw std::runtime_error("small_vector<uint8_t, 12, uint32_t> size should be 16");
  for(uint8_t i=0; i<100; ++i) {
    x.push_back(i);
  }
  x.clear();
  x.push_back(7);
  if(x[0] != 7) throw std::runtime_error("first element should be 7");
  Rprintf("small vector test done");
}

