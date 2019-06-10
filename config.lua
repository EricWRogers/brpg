assetDirectory = "assets/"
scriptDirectory = assetDirectory .. "scripts/"

math.randomseed( os.time() )

dofile(scriptDirectory .. "test.lua")