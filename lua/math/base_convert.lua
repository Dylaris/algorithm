local function base_convert(n, base)
    local characters = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    }

    if n == 0 then return "0" end
    if n < 0 then return "-" .. base_convert(-n, base) end

    local res = ""
    while n ~= 0 do
        res = characters[n % base + 1] .. res
        n = n // base
    end
    return res
end

print(base_convert(100, 7))
print(base_convert(-100, 7))
print(base_convert(-100, 6))