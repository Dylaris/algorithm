local Task = require("Task")

local task_queue = {}

local A = Task.new("A", 4, 4, nil, function (time, slice) print(string.format("TIME(%d):\tTask A is running (left: %d)", time, slice)) end)
local B = Task.new("B", 1, 2, nil, function (time, slice) print(string.format("TIME(%d):\tTask B is running (left: %d)", time, slice)) end)
local C = Task.new("C", 5, 3, nil, function (time, slice) print(string.format("TIME(%d):\tTask C is running (left: %d)", time, slice)) end)

-- Add task to task queue according to arrival time
local function how_to_add(task, queue)
    local insert_pos = #queue + 1
    for idx, item in ipairs(queue) do
        if task.arrival < item.arrival then
            insert_pos = idx
            break
        end
    end
    return insert_pos
end

-- Add task to task queue
Task.registry(A, task_queue, how_to_add)
Task.registry(B, task_queue, how_to_add)
Task.registry(C, task_queue, how_to_add)

local function fcfs_scheduler()
    local ticks = 1
    while #task_queue > 0 do
        local task = table.remove(task_queue, 1)
        while coroutine.status(task.executor) ~= "dead" do
            local _, new_ticks = coroutine.resume(task.executor, ticks)
            if new_ticks ~= nil then ticks = new_ticks end
        end
    end
end

fcfs_scheduler()