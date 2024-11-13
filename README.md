
# lua-wasm

Build & run Lua from source, within a web browser, using WebAssembly. Super lightweight starter kit.


## Installation

Install lua-wasm on Windows (Linux/MacOS coming soon.)

```bash
  git pull https://github.com/LukeGoule/lua-wasm
  cd lua-wasm
  .\build.bat
```

The above should pull this repository, and its dependencies, calling build.bat should then install & build the dependencies and then build the WASM program. A local test environmentt should launch (assuming Python3 is properly installed) which can be accessed via "http://localhost:8000/". See the browser console which should have some information dumped from Lua.