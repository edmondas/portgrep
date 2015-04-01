# portgrep

portgrep is a tool that can help to analize existing FreeBSD ports and how they use different variables and etc.

It is similar to this command:
```
find /usr/ports/ -name Makefile -exec grep -H STRING {} \;
```

## Installation
- fetch current version of portgrep
- extract it
- change directory
- make
- make install

## Usage
For example I want to know were and how Boost's shared_prt library is used:

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
