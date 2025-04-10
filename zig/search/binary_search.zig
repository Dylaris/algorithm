const std = @import("std");

fn binary_search(nums: []const i32, target: i32) ?usize {
    var left: usize = 0;
    var right: usize = nums.len - 1;

    while (left <= right) {
        const mid = left + (right - left) / 2;
        const mid_value = nums[mid];

        if (mid_value < target) {
            left = mid + 1;
        } else if (mid_value > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return null;
}

fn print(nums: []const i32) void {
    for (nums) |item| {
        std.debug.print("{} ", .{item});
    }
    std.debug.print("\n", .{});
}

pub fn main() void {
    const nums = [_]i32{ -1, 1, 1, 2, 3, 4, 5, 7 };

    print(&nums);

    const target1 = 6;
    const index1 = binary_search(&nums, target1);
    std.debug.print("target: {}, index: {?}\n", .{ target1, index1 });

    const target2 = 4;
    const index2 = binary_search(&nums, target2);
    std.debug.print("target: {}, index: {?}\n", .{ target2, index2 });
}
