local Task = require("Task")

local task_queue = {}

local A = Task.new("A", 4, 5)
local B = Task.new("B", 1, 7)
local C = Task.new("C", 6, 4)
local D = Task.new("D", 1, 2)

-- Add task to task queue
Task.registry(A, task_queue)
Task.registry(B, task_queue)
Task.registry(C, task_queue)
Task.registry(D, task_queue)

local function select(time)
    local remained_ticks = 1000 -- Assume 1000 is max execution time
    local pos = -1
    for idx, item in ipairs(task_queue) do
        if item.arrival <= time then
            if item.ticks < remained_ticks then
                remained_ticks = item.ticks
                pos = idx
            end
        end
    end
    return pos
end

local function stcf_scheduler()
    local ticks = 1
    while #task_queue > 0 do
        local pos = select(ticks)
        if pos ~= -1 then
            -- Have a runable task
            local task = table.remove(task_queue, pos)
            local _, new_ticks = coroutine.resume(task.executor, ticks)
            if new_ticks ~= nil then ticks = new_ticks end
            -- Not over, insert it to original position
            if task.ticks > 0 then table.insert(task_queue, pos, task) end
        else
            -- No task to run
            ticks = ticks + 1
        end
    end
end

stcf_scheduler()