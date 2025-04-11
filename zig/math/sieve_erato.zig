const std = @import("std");

fn sieve(n: usize) !i32 {
    var primes = try std.heap.page_allocator.alloc(bool, n + 1);
    for (primes) |*p| {
        p.* = true;
    }
    primes[0] = false;
    primes[1] = false;

    var i: usize = 2;
    while (i <= std.math.sqrt(n)) : (i += 1) {
        var j: usize = i * i;
        while (j <= n) : (j += i) {
            if (primes[j]) {
                primes[j] = false;
            }
        }
    }

    var count: i32 = 0;
    for (primes) |item| {
        if (item) {
            count += 1;
        }
    }

    return count;
}

pub fn main() void {
    std.debug.print("{!}\n", .{sieve(5)});
    std.debug.print("{!}\n", .{sieve(10)});
    std.debug.print("{!}\n", .{sieve(23)});
}
