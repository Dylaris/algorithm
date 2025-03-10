--[[
pseudo-code:

    min_idx <- 0 
    for i <- 0 to n - 2 do
        for j <- i to n - 1 do
            if array[min_idx] > array[j] then
            min_idx <- j
        swap(min_idx, i)
--]]

local function selection_sort(arr)
    local min_idx = 1
    for i = 1, #arr - 1, 1 do
        for j = i, #arr, 1 do
            if arr[min_idx] > arr[j] then
                min_idx = j
            end
        end
        -- swap
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    end
end

local function print(arr)
    for _, v in ipairs(arr) do
        io.write(" " .. tostring(v))
    end
    io.write("\n")
end

local function run()
    local arr = {9, 4, 5, 7, -2, -1, 0}
    print(arr)

    selection_sort(arr)
    print(arr)
end

run()
