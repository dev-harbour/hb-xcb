# Getting started

- [Harbour programming language](https://en.wikipedia.org/wiki/Harbour_(programming_language))
- [Homepage](https://harbour.github.io)
- Select your Harbour:
   - https://sourceforge.net/projects/harbour-project/files/
   - https://github.com/harbour/core
   - https://github.com/vszakats/hb

## Install on Windows

- (Harbour has no support for CygWin)

or

- [XCB out of Windows](https://xcb.freedesktop.org/win32port)

Unpack in the directory:

```
c:\XCB\bin *.dll
c:\XCB\include *.h
c:\XCB\lib *.a
```


## Install on Linux

```
sudo apt-get update
sudo apt-get install xcb

sudo apt-get install libxcb-image0-dev
sudo apt-get install libxcb-util-dev
sudo apt-get install libxcb-keysyms1-dev
sudo apt-get install libxcb-icccm4-dev
sudo apt-get install libxcb-cursor-dev
```

## Install hb-xcb

[Downloading hb-xcb](https://github.com/rjopek/hb-xcb/archive/refs/heads/main.zip)

Environment Variables

- Windows

   (Harbour has no support for CygWin)

   or

   ```
   set HB_WITH_XCB=c:\XCB\include
   set PATH=c:\XCB\bin;%path%
   ```

- Linux

   ```
   export HB_WITH_XCB=/usr/include
   ```

- Build static library:

   ```
   hbmk2 hbxcb.hbp
   ```

- Build and run sample and test code:

   ```
   cd cd examples/harbour
   hbmk2 example_00.prg
   ./example_00
   ```

[Edit me](https://github.com/rjopek/hb-xcb/edit/main/examples/README.md)
