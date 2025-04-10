local function lowbit(x)
    return x & -x
end

local function reset_lowest_one(x)
    return x & (x - 1)
end