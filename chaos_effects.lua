local ADDR_PREV_ONE_TIME_EFFECT = 0x3006008
local ADDR_CHAOS_EFFECTS = 0x3006018
local MAX_NUM_CHAOS_EFFECTS = 5
local CHAOS_EFFECT_SIZE = 8
local OFF_CHAOS_EXISTS = 0
local OFF_CHAOS_ID = 1
local OFF_CHAOS_TIMER = 2
local OFF_CHAOS_DATA = 4

local EFFECT_NAMES = {
    -- Duration effects
    "inverted controls",
    "water physics",
    "slow x movement",
    "fast x movement",
    "low gravity",
    "high gravity",
    "long echo",
    "deactivate ability",
    "suitless",
    "slow weapons",
    "arm missiles",
    "swap missiles",
    "charged shots",
    "shoot bombs",
    "move hud",
    "forward camera",
    "explosions",
    -- One time effects
    "spawn enemy",
    "spawn power bomb",
    "shot block",
    "freeze enemies",
    "screen shake",
    "knockback",
    "shine timer",
    "change energy or ammo",
    "pause game",
    "play sound",
    "color effect"
}

event.onexit(function()
    gui.clearGraphics()
end)

while true do

    -- Display previous one time effect
    local prevEffect = memory.read_u8(ADDR_PREV_ONE_TIME_EFFECT)
    if prevEffect ~= 0 then
        local name = EFFECT_NAMES[prevEffect + 1]
        gui.pixelText(2, 11, name, 0xE0FFD8D8, 0xA0000000)
    end

    -- Display duration effect
    local count = 0
    for i = 0, MAX_NUM_CHAOS_EFFECTS - 1 do
        local addr = ADDR_CHAOS_EFFECTS + (i * CHAOS_EFFECT_SIZE)
        if memory.read_u8(addr + OFF_CHAOS_EXISTS) ~= 0 then
            -- Get data
            local id = memory.read_u8(addr + OFF_CHAOS_ID)
            local name = EFFECT_NAMES[id + 1]
            local timer = memory.read_u16_le(addr + OFF_CHAOS_TIMER)
            local seconds = math.ceil(timer / 60)
            -- Display info
            local y = 19 + (count * 8)
            gui.pixelText(2, y, name .. " : " .. seconds, 0xE0D8D8FF, 0xA0000000)
            count = count + 1
        end
    end

    emu.frameadvance()

end
