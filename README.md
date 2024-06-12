# JmpC
JmpC is a C utilities library I created for myself, with a lot of utility functions I 
find myself wanting in standard C. It is implemented in c99, and is intended for useage
in c99 codebases, but *should* be compatible with c11 and up.

I've included the stuff I need, like vectors (matricies soon to come), Allocators, 
graphics, string utils, debug tools, etc. I'll document it all eventually, but today 
is not that day. **WINDOWS IS THE ONLY CURRENTLY SUPPORTED OS**. I have not implemented
certain functions for POSIX systems, and make use of the Windows API. I'll eventually 
support Linux/BSD/OSX, but that's a lot of work.

I've made extensive use of the Win32 API, which I've had to learn on the fly while making 
this, so there's a good amount of jank in that code. (The same can be said for all this code
tbh, I was learning on the fly this whole time)

## Planned
 - [ ] More string stuff
 - [ ] Linux implementation
 - [ ] More allocators.
 - [ ] Matricies.

## Building
To build the library for windows, use the `build.ps1` file.
```
./build
```

If you also want to build the test file, add the `test` option
```
./build test
./bin/test
```
