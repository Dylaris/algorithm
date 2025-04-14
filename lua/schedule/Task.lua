local Task = {
    name = "",
    arrival = 0,
    duration = 0,
    ticks = 0,
    priority = 0,
    action = function () print("hello") end,
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
        while time < object.arrival do
            print(string.format("TIME(%d):\tnothing", time))
            time = coroutine.yield(time + 1)
        end
        while object.ticks > 0 do
            object.ticks = object.ticks - 1
            object.action(time, object.ticks)
            time = coroutine.yield(time + 1)
        end
    end)

    return object
end

function Task:registry(queue, add)
    if type(queue) == "table" then
        table.insert(queue, add(self, queue), self)
    end
end

return Task