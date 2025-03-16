--[[
partition(arr)
  // 默认用第一个元素作为pivot
  pivot <- arr[0]
  lp <- 0
  rp <- n - 1
  while lp < rp do
    while lp < rp && arr[rp] >= pivot do
      rp--
    lp <- rp
    while lp < rp && arr[lp] < pivot do
      lp++
    rp <- lp

  pivot_idx <- lp
  arr[pivot_idx] <- pivot
  return pivot_idx // 这个就是分区界线

quick_sort(arr):
  limit <- partition(arr)
  quick_sort(arr[:limit-1])
  quick_sort(arr[limit+1:])
--]]

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

local function print(arr)
    for _, v in ipairs(arr) do
        io.write(" " .. tostring(v))
    end
    io.write("\n")
end

local function run()
    local arr = {9, 4, 5, 7, -2, -1, 0}
    print(arr)

    quick_sort(arr, 1, #arr)
    print(arr)
end

run()