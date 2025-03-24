local function binary_search(arr, target)
    local left, right = 1, #arr
    local mid
    while left <= right do
        mid = left + math.floor((right - left) / 2)
        if arr[mid] < target then
            left = mid + 1
        elseif arr[mid] > target then
            right = mid - 1
        else
            return mid
        end
    end
    return -1
end

local function run()
    local arr = {-1, 2, 3, 4, 6, 7, 9};
    for _, v in ipairs(arr) do
        io.write(" " .. tostring(v))
    end
    io.write("\n")

    print(string.format("target: %d\nindex: %d", 4, binary_search(arr, 4)))
    print(string.format("target: %d\nindex: %d", -2, binary_search(arr, -2)))
end

run()
