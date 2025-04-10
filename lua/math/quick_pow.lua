local function quick_pow(x, n)
    x = (n > 0) and x or 1 / x
    n = (n > 0) and n or -n

    local ans = 1
    while n ~= 0 do
        if n & 1 == 1 then
            ans = ans * x
        end
        x = x * x
        n = n >> 1
    end
    return ans
end

print(quick_pow(2.1, 9))
print(quick_pow(2.1, -9))