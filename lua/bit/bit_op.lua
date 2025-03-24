-- Useful bitwise operations.

-- lowbit(x): Extracts the lowest set bit of x.
-- Example: x = 12 (binary: 1100), LOWBIT(12) = 4 (binary: 0100)
-- This operation isolates the lowest set bit.
local function lowbit(x)
    return x & -x
end

-- reset_lowest_one(x): Clears the lowest set bit of x.
-- Example: x = 12 (binary: 1100), RESET_LOWESE_ONE(12) = 8 (binary: 1000)
-- This operation removes the lowest 1-bit from x.
local function reset_lowest_one(x)
    return x & (x - 1)
end