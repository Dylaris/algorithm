local function base_convert(n, base)
    if n == 0 then return "0" end
    if n < 0 then return "-" .. base_convert(-n, base) end

    local res = ""
    while n ~= 0 do
        res = n % base .. res
        n = n // base
    end
    return res
end

print(base_convert(100, 7))
print(base_convert(-100, 7))
print(base_convert(-100, 6))