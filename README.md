# rfolly

*Header files for the facebook `folly` library.*

Facebook Open Source Library (aka `folly`) is a C++ library similar to `boost` of fast and efficient library components. See here: https://github.com/facebook/folly

Many of the components are effectively header-only (with a little modification). These components include `fbvector`, `small_vector`, `fbstring`. 

## Modifications to source files

Source files are modified in the following way (recorded below for reproducibility):

* `folly-config.h` manually configured rather than relying on the CMake script. 
* * #define FOLLY_HAVE_UNALIGNED_ACCESS 1
* * #define FOLLY_HAVE_WEAK_SYMBOLS 0
* * #define R_USE_JEMALLOC -- this config parameter should be defined in R's Makevars or configure script. See below

* Append `folly/portability/Malloc.cpp` to the end of `folly/portability/Malloc.h`

## Installation

**Simple installation without jemalloc**

```
devtools::install_github("traversc/rfolly")
```

**Installation with jemalloc**

rfolly is intended to be used with jemalloc, but requires a little bit of work. This is optional. 

Step 1: remove previous installations of jemalloc. In Ubuntu:
```
sudo apt-get remove libjemalloc-dev
sudo apt-get remove libjemalloc2
```

Step 2: download, configure and install jemalloc. 

You can download it from here: https://github.com/jemalloc/jemalloc/releases/download/5.2.1/jemalloc-5.2.1.tar.bz2
```
./configure --disable-initial-exec-tls
make
sudo make install
```

Step 3: install rfolly with configure args:
```
remotes::install_github("traversc/rfolly",configure.args="--with-jemalloc")
```

## Things needed to get CRAN-ready

* Sort out license
* Figure out which components are available
* Get rid of cpp files and components that are not header only
* Proper testing
* Documentation, help files
* ???

If you'd like to collaborate, send me a message and/or pull request. 

