const std = @import("std");

fn quick_pow(x: f32, n: i32) f32 {
    var x1: f32 = x;
    var n1: i32 = n;
    if (n < 0) {
        x1 = 1 / x;
        n1 = -n;
    }
    var ans: f32 = 1;
    while (n1 != 0) {
        if ((n1 & 1) == 1) {
            ans *= x1;
        }
        x1 *= x1;
        n1 >>= 1;
    }
    return ans;
}

pub fn main() void {
    std.debug.print("2^4: {}\n", .{quick_pow(2, 4)});
    std.debug.print("2^-4: {}\n", .{quick_pow(2, -4)});
    std.debug.print("2.1^6: {}\n", .{quick_pow(2.1, 6)});
    std.debug.print("2.1^-6: {}\n", .{quick_pow(2.1, -6)});
    std.debug.print("2.1^0: {}\n", .{quick_pow(2.1, 0)});
}
