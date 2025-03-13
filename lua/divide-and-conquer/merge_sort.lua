--[[
merge_sort(A):
  if numberof(A) > 1 then
    B <- A[0:n//2]
    C <- A[n//2:n]
    merge_sort(B)
    merge_sort(C)
    merge(B, C)
  
merge(B, C):
  p = 0 // 指向 B
  q = 0 // 指向 C
  i = 0 // 结果数组 res 的索引

  while p < len(B) && q < len(C) do
    if B[p] <= C[q] then
      res[i++] = B[p++] // 取 B 中较小的元素
    else 
      res[i++] = C[q++] // 取 C 中较小的元素

  if p < len(B) then
    copy(B[p:], res, i) // 复制 B 中剩余的元素到 A
  
  if q < len(C) then
    copy(C[q:], res, i) // 复制 C 中剩余的元素到 A
--]]

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

    for i = left, right, 1 do
        arr[i] = res[i - left + 1]
    end
end

local function merge_sort(arr, left, right)
    if left < right then
        local mid = math.floor((left + right) / 2)
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)
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

    merge_sort(arr, 1, #arr)
    print(arr)
end

run()

