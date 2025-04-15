local Task = require("Task")

local task_queue = {}

local A = Task.new("A", 4, 4)
local B = Task.new("B", 1, 4)
local C = Task.new("C", 5, 3)
local D = Task.new("D", 1, 2)

-- Add task to task queue
Task.registry(A, task_queue)
Task.registry(B, task_queue)
Task.registry(C, task_queue)
Task.registry(D, task_queue)

local function select(time)
    local pos = -1
    for idx, item in ipairs(task_queue) do
        if item.arrival <= time then
            pos = idx
            break
        end
    end
    return pos
end

local function fcfs_scheduler()
    local ticks = 1
    while #task_queue > 0 do
        local pos = select(ticks)
        if pos ~= -1 then
            -- Have a runable task
            local task = table.remove(task_queue, pos)
            while coroutine.status(task.executor) ~= "dead" do
                local _, new_ticks = coroutine.resume(task.executor, ticks)
                if new_ticks ~= nil then ticks = new_ticks end
            end
        else
            -- No task to run
            ticks = ticks + 1
        end
    end
end

fcfs_scheduler()