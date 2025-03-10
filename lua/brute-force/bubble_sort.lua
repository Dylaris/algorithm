--[[
pseudo-code:
    for i <- n-1 downto 1 do
        for j <- 0 to i-1 do
            if arr[j] > arr[j+1] then
                swap(j, j+1)
--]]

local function bubble_sort(arr)
    for i = #arr, 2, -1 do
        for j = 1, i - 1, 1 do
            if arr[j] > arr[j + 1] then
                -- swap
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            end
        end
    end
end

local function print(arr)
    for i = 1, #arr, 1 do
        io.write(" " .. tostring(arr[i]))
    end
    io.write("\n")
end

local function run()
    local arr = {3, 6, 1, -9, -6, 5, 23, 1}
    print(arr)

    bubble_sort(arr)
    print(arr)
end

run()
