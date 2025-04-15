local Task = {
    name = "",
    arrival = 0,
    duration = 0,
    ticks = 0,
    priority = 0,
    action = function (time, task)
        print(string.format("TIME(%d):\tTask %s is running (left: %d)", time, task.name, task.ticks))
    end,
    executor = nil
}
Task.__index = Task

function Task.new(name, arrival, duration, priority, action)
    local object = {}
    setmetatable(object, Task)

    object.name     = name or object.name
    object.arrival  = arrival or object.arrival
    object.duration = duration or object.duration
    object.ticks    = duration or object.ticks
    object.priority = priority or object.priority
    object.action   = action or object.action
    object.executor = coroutine.create(function (time)
        while object.ticks > 0 do
            object.ticks = object.ticks - 1
            object.action(time, object)
            time = coroutine.yield(time + 1)
        end
    end)

    return object
end

function Task:registry(queue)
    if type(queue) == "table" then
        for idx, item in ipairs(queue) do
            if self.arrival < item.arrival then
                table.insert(queue, idx, self)
                return
            end
        end
        table.insert(queue, self)
    end
end

return Task