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

local function print_tbl(arr)
    for i = 1, #arr, 1 do
        io.write(" " .. tostring(arr[i]))
    end
    io.write("\n")
end

local function run()
    local arr = {3, 6, 1, -9, -6, 5, 23, 1}
    print_tbl(arr)

    bubble_sort(arr)
    print_tbl(arr)
end

run()
