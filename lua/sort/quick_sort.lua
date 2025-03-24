local function partition(arr, left, right)
    local pivot = arr[left]
    while left < right do
        while left < right and arr[right] >= pivot do
            right = right - 1
        end
        arr[left] = arr[right]

        while left < right and arr[left] <= pivot do
            left = left + 1
        end
        arr[right] = arr[left]
    end
    arr[left] = pivot
    return left
end

local function quick_sort(arr, left, right)
    if left >= right then return end

    local mid = partition(arr, left, right)
    quick_sort(arr, left, mid - 1)
    quick_sort(arr, mid + 1, right)
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

    quick_sort(arr, 1, #arr)
    print_tbl(arr)
end

run()