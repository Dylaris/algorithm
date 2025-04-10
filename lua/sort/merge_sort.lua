local function merge(arr, left, mid, right)
    local p, q = left, mid + 1
    local res = {}

    while p <= mid and q <= right do
        if arr[p] <= arr[q] then
            res[#res+1] = arr[p]
            p = p + 1
        else
            res[#res+1] = arr[q]
            q = q + 1
        end
    end

    while p <= mid do
        res[#res+1] = arr[p]
        p = p + 1
    end

    while q <= right do
        res[#res+1] = arr[q]
        q = q + 1
    end

    for i = left, right do
        arr[i] = res[i - left + 1]
    end
end

local function merge_sort(arr, left, right)
    if left >= right then return end

    local mid = math.floor((left + right) / 2)
    merge_sort(arr, left, mid)
    merge_sort(arr, mid + 1, right)
    merge(arr, left, mid, right)
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

    merge_sort(arr, 1, #arr)
    print_tbl(arr)
end

run()
