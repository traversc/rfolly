AC_INIT(rfolly, 0.0.1, traversc@gmail.com)
AC_PATH_PROG([PKGCONF],[pkg-config],[],[$PATH:/usr/local/bin:ext/bin:ext:/sw/bin:/opt/bin:/opt/local/bin])

########################################################
### Configure args

AC_ARG_WITH([jemalloc],
            AC_HELP_STRING([--with-jemalloc],
                           [Whether to use jemalloc if available]),
            [use_jemalloc="true"])
            
AC_ARG_WITH([jemalloc-include],
            AC_HELP_STRING([--with-jemalloc-include=INCLUDE_PATH],
                           [the location of jemalloc header files]),
            jemalloc_include_path=$withval])
            
AC_ARG_WITH([jemalloc-lib],
            AC_HELP_STRING([--with-jemalloc-lib=LIB_PATH],
                           [the location of jemalloc library files]),
            [jemalloc_lib_path=$withval])


########################################################
#### Version value function

getVersion()
{
VERSION_STRING=$1
MAJOR=`echo $VERSION_STRING | cut -d. -f1`
MINOR=`echo $VERSION_STRING | cut -d. -f2`
RELEASE=`echo $VERSION_STRING | cut -d. -f3`
echo $(($MAJOR*100000+$MINOR*100+$RELEASE))
}


########################################################
# Search for jemalloc

if test "xx$use_jemalloc" != "xx"; then

  jemalloc_USE_DEFINE=""
  jemalloc_INCLUDE_PATH=""
  jemalloc_LIBS=""
  
  echo pkg-config: $PKGCONF
  
  if test "xx$jemalloc_include_path" != "xx"; then
    echo "Using user-defined jemalloc install paths"
      jemalloc_LIBS="-L${jemalloc_lib_path}"
      jemalloc_INCLUDE_PATH="-I${jemalloc_include_path}"
      jemalloc_USE_DEFINE="-DR_USE_JEMALLOC"
  elif test "xx$PKGCONF" != "xx"; then
    if "${PKGCONF}" --exists jemalloc; then
      echo "jemalloc ${VERSION_STRING} dynamic library detected"
      jemalloc_LIBS=`"${PKGCONF}" --libs jemalloc`
      jemalloc_INCLUDE_PATH=`"${PKGCONF}" --cflags-only-I jemalloc`
      jemalloc_USE_DEFINE="-DR_USE_JEMALLOC"
    fi
  fi
  
  echo libs: $jemalloc_LIBS
  echo include: $jemalloc_INCLUDE_PATH

fi

AC_SUBST([jemalloc_INCLUDE_PATH], $jemalloc_INCLUDE_PATH)
AC_SUBST([jemalloc_LIBS], $jemalloc_LIBS)
AC_SUBST([jemalloc_USE_DEFINE], $jemalloc_USE_DEFINE)


AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT
