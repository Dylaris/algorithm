local function sieve(n)
    local prime = {}
    for i = 0, n do prime[i] = true end
    prime[0] = false
    prime[1] = false

    for i = 2, math.floor(math.sqrt(n)) do
        for j = i * i, n, i do
            prime[j] = false
        end
    end

    local count = 0
    for i = 0, n do
        if prime[i] then count = count + 1 end
    end

    return count
end

print(sieve(5))
print(sieve(10))
print(sieve(23))