portgrep is a tool that can help to analize existing FreeBSD ports and how they use different variables and etc.

It is similar to this command:
```
find /usr/ports/ -name Makefile -exec grep -H STRING {} \;
```

### Installation ###
  1. fetch current version of portgrep
  1. extract it
  1. change directory
  1. make
  1. make install

### Usage ###
For example I want to know were and how Boost's shared\_prt library is used:
```
portgrep Makefile shared_ptr
```

Output:
```
Found in: /usr/ports/devel/libopkele/Makefile
BUILD_DEPENDS=  ${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

Found in: /usr/ports/devel/monotone/Makefile
BUILD_DEPENDS=  ${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs \

...
```