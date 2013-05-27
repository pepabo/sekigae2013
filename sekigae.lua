--[[ 
# Name
Sekigae program with Lua/LuaJIT for paperboy&co fresher.

# Compatibility
It works with both of Lua and LuaJIT

# Notes
install `luarocks install inspect` before use.

# Usage
`$ luajit sekigae.lua`

# URL
https://github.com/y-ken/paperboy-sekigae

# References
* http://en.wikipedia.org/wiki/Fisher-Yates_shuffle
* http://www.gammon.com.au/forum/?id=9908

# Tips
[http://y-ken.hatenablog.com/entry/macosx-install-lua-luajit-luarocks](The Guide to install Lua/LuaJIT for Mac OSX with brew.)
]]

math.randomseed(os.time())
inspect = require 'inspect'
names = {"おっくん", "きたけー", "たけお", "ぐっさん"}

function shuffle(array)
  local arrayCount = #array
  for i = arrayCount, 2, -1 do
    local j = math.random(1, i)
    array[i], array[j] = array[j], array[i]
  end
  return array
end

print(inspect(shuffle(names)))
