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

local function print_tbl(arr)
    for _, v in ipairs(arr) do
        io.write(" " .. tostring(v))
    end
    io.write("\n")
end

local function run()
    local arr = {9, 4, 5, 7, -2, -1, 0}
    print_tbl(arr)

    selection_sort(arr)
    print_tbl(arr)
end

run()
