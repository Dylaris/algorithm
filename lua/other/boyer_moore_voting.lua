local function majority_element(nums)
    if not nums or #nums == 0 then return nil end

    local winner, count = nil, 0
    for _, num in ipairs(nums) do
        if count == 0 then winner = num end
        if winner == num then
            count = count + 1
        else
            count = count - 1
        end
    end
    return winner
end

local nums = {1, 1, 1, 1, 4, 5, 6}
print(majority_element(nums))
